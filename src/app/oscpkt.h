#ifndef OSCPKT_HH
#define OSCPKT_HH

#include <stdint.h>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>

#if defined(OSCPKT_OSTREAM_OUTPUT) || defined(OSCPKT_TEST)
#include <iostream>
#endif

void myprintf(char* string);

namespace oscpkt
{

	class TimeTag
	{
		uint64_t v;

	public:
		TimeTag() : v(1) {}
		explicit TimeTag(uint64_t w) : v(w) {}
		operator uint64_t() const { return v; }
		static TimeTag immediate() { return TimeTag(1); }
	};

	// 
	enum
	{
		TYPE_TAG_TRUE  = 'T',
		TYPE_TAG_FALSE = 'F',
		TYPE_TAG_INT32 = 'i',
		TYPE_TAG_INT64 = 'h',
		TYPE_TAG_FLOAT = 'f',
		TYPE_TAG_DOUBLE= 'd',
		TYPE_TAG_STRING= 's',
		TYPE_TAG_BLOB  = 'b'
	};

	//
	template <typename Type> Type ceil4(Type p) { return (Type)((size_t(p) + 3) & (~size_t(3))); }

	//
	inline bool isZeroPaddingCorrect(const char *p)
	{
		const char *q = ceil4(p);
		for (; p < q; ++p)
			if (*p != 0)
			{
				return false;
			}
		return true;
	}

	//
	template <typename POD> union PodBytes {
		char bytes[sizeof(POD)];
		POD value;
	};

	//
	inline bool isBigEndian()
	{
		PodBytes<int32_t> p;
		p.value = 0x12345678;
		return p.bytes[0] == 0x12;
	}

	//
	template <typename POD> POD bytes2pod(const char *bytes)
	{
		PodBytes<POD> p;
		for (size_t i = 0; i < sizeof(POD); ++i)
		{
			if (isBigEndian())
				p.bytes[i] = bytes[i];
			else
				p.bytes[i] = bytes[sizeof(POD) - i - 1];
		}
		return p.value;
	}

	//
	template <typename POD> void pod2bytes(const POD value, char *bytes)
	{
		PodBytes<POD> p;
		p.value = value;
		for (size_t i = 0; i < sizeof(POD); ++i)
		{
			if (isBigEndian())
				bytes[i] = p.bytes[i];
			else
				bytes[i] = p.bytes[sizeof(POD) - i - 1];
		}
	}

	//
	struct Storage
	{
		std::vector<char> data;
		Storage() { data.reserve(200); }
		char *getBytes(size_t sz)
		{
			assert((data.size() & 3) == 0);
			if (data.size() + sz > data.capacity())
			{
				data.reserve((data.size() + sz) * 2);
			}
			size_t sz4 = ceil4(sz);
			size_t pos = data.size();
			data.resize(pos + sz4); // resize will fill with zeros, so the zero padding is OK
			return &(data[pos]);
		}
		char *begin() { return data.size() ? &data.front() : 0; }
		char *end() { return begin() + size(); }
		const char *begin() const { return data.size() ? &data.front() : 0; }
		const char *end() const { return begin() + size(); }
		size_t size() const { return data.size(); }
		void assign(const char *beg, const char *end) { data.assign(beg, end); }
		void clear() { data.resize(0); }
	};

	bool fullPatternMatch(const std::string &pattern, const std::string &path);
	bool partialPatternMatch(const std::string &pattern, const std::string &path);

#define OSCPKT_SET_ERR(errcode) \
  do                            \
  {                             \
    if (!err)                   \
      err = errcode;            \
  } while (0)

	typedef enum {
		OK_NO_ERROR = 0,
		// errors raised by the Message class:
		MALFORMED_ADDRESS_PATTERN,
		MALFORMED_TYPE_TAGS,
		MALFORMED_ARGUMENTS,
		UNHANDLED_TYPE_TAGS,
		// errors raised by ArgReader
		TYPE_MISMATCH,
		NOT_ENOUGH_ARG,
		PATTERN_MISMATCH,
		// errors raised by PacketReader/PacketWriter
		INVALID_BUNDLE,
		INVALID_PACKET_SIZE,
		BUNDLE_REQUIRED_FOR_MULTI_MESSAGES
	} ErrorCode;

	class Message
	{
		TimeTag time_tag;
		std::string address;
		std::string type_tags;
		std::vector<std::pair<size_t, size_t>> arguments; // array of pairs (pos,size), pos being an index into the 'storage' array.
		Storage storage;                                  // the arguments data is stored here
		ErrorCode err;

	public:
		/** ArgReader is used for popping arguments from a Message, holds a
			pointer to the original Message, and maintains a local error code */
		class ArgReader
		{
			const Message *msg;
			ErrorCode err;
			size_t arg_idx; // arg index of the next arg that will be popped out.
		public:
			ArgReader(const Message &m, ErrorCode e = OK_NO_ERROR) : msg(&m), err(msg->getErr()), arg_idx(0)
			{
				if (e != OK_NO_ERROR && err == OK_NO_ERROR)
					err = e;
			}
			ArgReader(const ArgReader &other) : msg(other.msg), err(other.err), arg_idx(other.arg_idx) {}
			bool isBool() { return currentTypeTag() == TYPE_TAG_TRUE || currentTypeTag() == TYPE_TAG_FALSE; }
			bool isInt32() { return currentTypeTag() == TYPE_TAG_INT32; }
			bool isInt64() { return currentTypeTag() == TYPE_TAG_INT64; }
			bool isFloat() { return currentTypeTag() == TYPE_TAG_FLOAT; }
			bool isDouble() { return currentTypeTag() == TYPE_TAG_DOUBLE; }
			bool isStr() { return currentTypeTag() == TYPE_TAG_STRING; }
			bool isBlob() { return currentTypeTag() == TYPE_TAG_BLOB; }

			size_t nbArgRemaining() const { return msg->arguments.size() - arg_idx; }
			bool isOk() const { return err == OK_NO_ERROR; }
			operator bool() const { return isOk(); } // implicit bool conversion is handy here
			/** call this at the end of the popXXX() chain to make sure everything is ok and
				all arguments have been popped */
			bool isOkNoMoreArgs() const { return err == OK_NO_ERROR && nbArgRemaining() == 0; }
			ErrorCode getErr() const { return err; }

			/** retrieve an int32 argument */
			ArgReader &popInt32(int32_t &i) { return popPod<int32_t>(TYPE_TAG_INT32, i); }
			/** retrieve an int64 argument */
			ArgReader &popInt64(int64_t &i) { return popPod<int64_t>(TYPE_TAG_INT64, i); }
			/** retrieve a single precision floating point argument */
			ArgReader &popFloat(float &f) { return popPod<float>(TYPE_TAG_FLOAT, f); }
			/** retrieve a double precision floating point argument */
			ArgReader &popDouble(double &d) { return popPod<double>(TYPE_TAG_DOUBLE, d); }
			/** retrieve a string argument (no check performed on its content, so it may contain any byte value except 0) */
			ArgReader &popStr(std::string &s)
			{
				if (precheck(TYPE_TAG_STRING))
				{
					s = argBeg(arg_idx++);
				}
				return *this;
			}
			/** retrieve a binary blob */
			ArgReader &popBlob(std::vector<char> &b)
			{
				if (precheck(TYPE_TAG_BLOB))
				{
					b.assign(argBeg(arg_idx) + 4, argEnd(arg_idx));
					++arg_idx;
				}
				return *this;
			}
			/** retrieve a boolean argument */
			ArgReader &popBool(bool &b)
			{
				b = false;
				if (arg_idx >= msg->arguments.size())
					OSCPKT_SET_ERR(NOT_ENOUGH_ARG);
				else if (currentTypeTag() == TYPE_TAG_TRUE)
					b = true;
				else if (currentTypeTag() == TYPE_TAG_FALSE)
					b = false;
				else
					OSCPKT_SET_ERR(TYPE_MISMATCH);
				++arg_idx;
				return *this;
			}
			/** skip whatever comes next */
			ArgReader &pop()
			{
				if (arg_idx >= msg->arguments.size())
					OSCPKT_SET_ERR(NOT_ENOUGH_ARG);
				else
					++arg_idx;
				return *this;
			}

		private:
			const char *argBeg(size_t idx)
			{
				if (err || idx >= msg->arguments.size())
					return 0;
				else
					return msg->storage.begin() + msg->arguments[idx].first;
			}
			const char *argEnd(size_t idx)
			{
				if (err || idx >= msg->arguments.size())
					return 0;
				else
					return msg->storage.begin() + msg->arguments[idx].first + msg->arguments[idx].second;
			}
			int currentTypeTag()
			{
				if (!err && arg_idx < msg->type_tags.size())
					return msg->type_tags[arg_idx];
				else
					OSCPKT_SET_ERR(NOT_ENOUGH_ARG);
				return -1;
			}
			template <typename POD>
			ArgReader &popPod(int tag, POD &v)
			{
				if (precheck(tag))
				{
					v = bytes2pod<POD>(argBeg(arg_idx));
					++arg_idx;
				}
				else
					v = POD(0);
				return *this;
			}
			/* pre-check stuff before popping an argument from the message */
			bool precheck(int tag)
			{
				if (arg_idx >= msg->arguments.size())
					OSCPKT_SET_ERR(NOT_ENOUGH_ARG);
				else if (!err && currentTypeTag() != tag)
					OSCPKT_SET_ERR(TYPE_MISMATCH);
				return err == OK_NO_ERROR;
			}
		};

		Message() { clear(); }
		Message(const std::string &s, TimeTag tt = TimeTag::immediate()) : time_tag(tt), address(s), err(OK_NO_ERROR) {}
		Message(const void *ptr, size_t sz, TimeTag tt = TimeTag::immediate())
		{
			buildFromRawData(ptr, sz);
			time_tag = tt;
		}

		bool isOk() const { return err == OK_NO_ERROR; }
		ErrorCode getErr() const { return err; }

		/** return the type_tags string, with its initial ',' stripped. */
		const std::string &typeTags() const { return type_tags; }
		/** retrieve the address pattern. If you want to follow to the whole OSC spec, you
			have to handle its matching rules for address specifications -- this file does
			not provide this functionality */
		const std::string &addressPattern() const { return address; }
		TimeTag timeTag() const { return time_tag; }
		/** clear the message and start a new message with the supplied address and time_tag. */
		Message &init(const std::string &addr, TimeTag tt = TimeTag::immediate())
		{
			clear();
			address = addr;
			time_tag = tt;
			if (address.empty() || address[0] != '/')
				OSCPKT_SET_ERR(MALFORMED_ADDRESS_PATTERN);
			return *this;
		}

		ArgReader match(const std::string &test) const
		{
			return ArgReader(*this, fullPatternMatch(address.c_str(), test.c_str()) ? OK_NO_ERROR : PATTERN_MISMATCH);
		}
		/** return true if the 'test' path matched by the first characters of addressPattern().
			For ex. ("/foo/bar").partialMatch("/foo/") is true */
		ArgReader partialMatch(const std::string &test) const
		{
			return ArgReader(*this, partialPatternMatch(address.c_str(), test.c_str()) ? OK_NO_ERROR : PATTERN_MISMATCH);
		}
		ArgReader arg() const { return ArgReader(*this, OK_NO_ERROR); }

		/** build the osc message for raw data (the message will keep a copy of that data) */
		void buildFromRawData(const void *ptr, size_t sz)
		{
			clear();
			storage.assign((const char *)ptr, (const char *)ptr + sz);
			const char *address_beg = storage.begin();
			const char *address_end = (const char *)memchr(address_beg, 0, storage.end() - address_beg);
			if (!address_end || !isZeroPaddingCorrect(address_end + 1) || address_beg[0] != '/')
			{
				OSCPKT_SET_ERR(MALFORMED_ADDRESS_PATTERN);
				return;
			}
			else
				address.assign(address_beg, address_end);

			const char *type_tags_beg = ceil4(address_end + 1);
			const char *type_tags_end = (const char *)memchr(type_tags_beg, 0, storage.end() - type_tags_beg);
			if (!type_tags_end || !isZeroPaddingCorrect(type_tags_end + 1) || type_tags_beg[0] != ',')
			{
				OSCPKT_SET_ERR(MALFORMED_TYPE_TAGS);
				return;
			}
			else
				type_tags.assign(type_tags_beg + 1, type_tags_end); // we do not copy the initial ','

			const char *arg = ceil4(type_tags_end + 1);
			assert(arg <= storage.end());
			size_t iarg = 0;
			while (isOk() && iarg < type_tags.size())
			{
				assert(arg <= storage.end());
				size_t len = getArgSize(type_tags[iarg], arg);
				if (isOk())
					arguments.push_back(std::make_pair(arg - storage.begin(), len));
				arg += ceil4(len);
				++iarg;
			}
			if (iarg < type_tags.size() || arg != storage.end())
			{
				OSCPKT_SET_ERR(MALFORMED_ARGUMENTS);
			}
		}

		/* below are all the functions that serve when *writing* a message */
		Message &pushBool(bool b)
		{
			type_tags += (b ? TYPE_TAG_TRUE : TYPE_TAG_FALSE);
			arguments.push_back(std::make_pair(storage.size(), storage.size()));
			return *this;
		}
		Message &pushInt32(int32_t i) { return pushPod(TYPE_TAG_INT32, i); }
		Message &pushInt64(int64_t h) { return pushPod(TYPE_TAG_INT64, h); }
		Message &pushFloat(float f) { return pushPod(TYPE_TAG_FLOAT, f); }
		Message &pushDouble(double d) { return pushPod(TYPE_TAG_DOUBLE, d); }
		Message &pushStr(const std::string &s)
		{
			assert(s.size() < 2147483647); // insane values are not welcome
			type_tags += TYPE_TAG_STRING;
			arguments.push_back(std::make_pair(storage.size(), s.size() + 1));
			strcpy(storage.getBytes(s.size() + 1), s.c_str());
			return *this;
		}
		Message &pushBlob(void *ptr, size_t num_bytes)
		{
			assert(num_bytes < 2147483647); // insane values are not welcome
			type_tags += TYPE_TAG_BLOB;
			arguments.push_back(std::make_pair(storage.size(), num_bytes + 4));
			pod2bytes<int32_t>((int32_t)num_bytes, storage.getBytes(4));
			if (num_bytes)
				memcpy(storage.getBytes(num_bytes), ptr, num_bytes);
			return *this;
		}

		/** reset the message to a clean state */
		void clear()
		{
			address.clear();
			type_tags.clear();
			storage.clear();
			arguments.clear();
			err = OK_NO_ERROR;
			time_tag = TimeTag::immediate();
		}

		/** write the raw message data (used by PacketWriter) */
		void packMessage(Storage &s, bool write_size) const
		{
			if (!isOk())
				return;
			size_t l_addr = address.size() + 1, l_type = type_tags.size() + 2;
			if (write_size)
				pod2bytes<uint32_t>(uint32_t(ceil4(l_addr) + ceil4(l_type) + ceil4(storage.size())), s.getBytes(4));
			strcpy(s.getBytes(l_addr), address.c_str());
			strcpy(s.getBytes(l_type), ("," + type_tags).c_str());
			if (storage.size())
				memcpy(s.getBytes(storage.size()), const_cast<Storage &>(storage).begin(), storage.size());
		}

	private:
		/* get the number of bytes occupied by the argument */
		size_t getArgSize(int type, const char *p)
		{
			if (err)
				return 0;
			size_t sz = 0;
			assert(p >= storage.begin() && p <= storage.end());
			switch (type)
			{
			case TYPE_TAG_TRUE:
			case TYPE_TAG_FALSE:
				sz = 0;
				break;
			case TYPE_TAG_INT32:
			case TYPE_TAG_FLOAT:
				sz = 4;
				break;
			case TYPE_TAG_INT64:
			case TYPE_TAG_DOUBLE:
				sz = 8;
				break;
			case TYPE_TAG_STRING:
			{
				const char *q = (const char *)memchr(p, 0, storage.end() - p);
				if (!q)
					OSCPKT_SET_ERR(MALFORMED_ARGUMENTS);
				else
					sz = (q - p) + 1;
			}
			break;
			case TYPE_TAG_BLOB:
			{
				if (p == storage.end())
				{
					OSCPKT_SET_ERR(MALFORMED_ARGUMENTS);
					return 0;
				}
				sz = 4 + bytes2pod<uint32_t>(p);
			}
			break;
			default:
			{
				OSCPKT_SET_ERR(UNHANDLED_TYPE_TAGS);
				return 0;
			}
			break;
			}
			if (p + sz > storage.end() || /* string or blob too large.. */
				p + sz < p /* or even blob so large that it did overflow */)
			{
				OSCPKT_SET_ERR(MALFORMED_ARGUMENTS);
				return 0;
			}
			if (!isZeroPaddingCorrect(p + sz))
			{
				OSCPKT_SET_ERR(MALFORMED_ARGUMENTS);
				return 0;
			}
			return sz;
		}

		template <typename POD>
		Message &pushPod(int tag, POD v)
		{
			type_tags += (char)tag;
			arguments.push_back(std::make_pair(storage.size(), sizeof(POD)));
			pod2bytes(v, storage.getBytes(sizeof(POD)));
			return *this;
		}

	};

	class PacketReader
	{
	public:
		PacketReader() { err = OK_NO_ERROR; }
		/** pointer and size of the osc packet to be parsed. */
		PacketReader(const void *ptr, size_t sz) { init(ptr, sz); }

		void init(const void *ptr, size_t sz)
		{
			err = OK_NO_ERROR;
			messages.clear();
			if ((sz % 4) == 0)
			{
				parse((const char *)ptr, (const char *)ptr + sz, TimeTag::immediate());
			}
			else
				OSCPKT_SET_ERR(INVALID_PACKET_SIZE);
			it_messages = messages.begin();
		}

		/** extract the next osc message from the packet. return 0 when all messages have been read, or in case of error. */
		Message *popMessage()
		{
			if (!err && !messages.empty() && it_messages != messages.end())
				return &*it_messages++;
			else
				return 0;
		}
		bool isOk() const { return err == OK_NO_ERROR; }
		ErrorCode getErr() const { return err; }

	private:
		std::list<Message> messages;
		std::list<Message>::iterator it_messages;
		ErrorCode err;

		void parse(const char *beg, const char *end, TimeTag time_tag)
		{
			assert(beg <= end && !err);
			assert(((end - beg) % 4) == 0);

			if (beg == end)
				return;
			if (*beg == '#')
			{
				/* it's a bundle */
				if (end - beg >= 20 && memcmp(beg, "#bundle\0", 8) == 0)
				{
					TimeTag time_tag2(bytes2pod<uint64_t>(beg + 8));
					const char *pos = beg + 16;
					do
					{
						uint32_t sz = bytes2pod<uint32_t>(pos);
						pos += 4;
						if ((sz & 3) != 0 || pos + sz > end || pos + sz < pos)
						{
							OSCPKT_SET_ERR(INVALID_BUNDLE);
						}
						else
						{
							parse(pos, pos + sz, time_tag2);
							pos += sz;
						}
					} while (!err && pos != end);
				}
				else
				{
					OSCPKT_SET_ERR(INVALID_BUNDLE);
				}
			}
			else
			{
				messages.push_back(Message(beg, end - beg, time_tag));
				if (!messages.back().isOk())
					OSCPKT_SET_ERR(messages.back().getErr());
			}
		}
	};

	class PacketWriter
	{
	public:
		PacketWriter() { init(); }
		PacketWriter &init()
		{
			err = OK_NO_ERROR;
			storage.clear();
			bundles.clear();
			return *this;
		}

		/** begin a new bundle. If you plan to pack more than one message in the Osc packet, you have to
			put them in a bundle. Nested bundles inside bundles are also allowed. */
		PacketWriter &startBundle(TimeTag ts = TimeTag::immediate())
		{
			char *p;
			if (bundles.size())
				storage.getBytes(4); // hold the bundle size
			p = storage.getBytes(8);
			strcpy(p, "#bundle");
			bundles.push_back(p - storage.begin());
			p = storage.getBytes(8);
			pod2bytes<uint64_t>(ts, p);
			return *this;
		}
		/** close the current bundle. */
		PacketWriter &endBundle()
		{
			if (bundles.size())
			{
				if (storage.size() - bundles.back() == 16)
				{
					pod2bytes<uint32_t>(0, storage.getBytes(4)); // the 'empty bundle' case, not very elegant
				}
				if (bundles.size() > 1)
				{ // no size stored for the top-level bundle
					pod2bytes<uint32_t>(uint32_t(storage.size() - bundles.back()), storage.begin() + bundles.back() - 4);
				}
				bundles.pop_back();
			}
			else
				OSCPKT_SET_ERR(INVALID_BUNDLE);
			return *this;
		}

		/** insert an Osc message into the current bundle / packet.
		 */
		PacketWriter &addMessage(const Message &msg)
		{
			if (storage.size() != 0 && bundles.empty())
				OSCPKT_SET_ERR(BUNDLE_REQUIRED_FOR_MULTI_MESSAGES);
			else
				msg.packMessage(storage, bundles.size() > 0);
			if (!msg.isOk())
				OSCPKT_SET_ERR(msg.getErr());
			return *this;
		}

		/** the error flag will be raised if an opened bundle is not closed, or if more than one message is
			inserted in the packet without a bundle */
		bool isOk() { return err == OK_NO_ERROR; }
		ErrorCode getErr() { return err; }

		/** return the number of bytes of the osc packet -- will always be a
			multiple of 4 -- returns 0 if the construction of the packet has
			failed. */
		uint32_t packetSize() { return err ? 0 : (uint32_t)storage.size(); }

		/** return the bytes of the osc packet (NULL if the construction of the packet has failed) */
		char *packetData() { return err ? 0 : storage.begin(); }

	private:
		std::vector<size_t> bundles; // hold the position in the storage array of the beginning marker of each bundle
		Storage storage;
		ErrorCode err;
	};

	// see the OSC spec for the precise pattern matching rules
	inline const char *internalPatternMatch(const char *pattern, const char *path)
	{
		while (*pattern)
		{
			const char *p = pattern;
			if (*p == '?' && *path)
			{
				++p;
				++path;
			}
			else if (*p == '[' && *path)
			{ // bracketted range, e.g. [a-zABC]
				++p;
				bool reverse = false;
				if (*p == '!')
				{
					reverse = true;
					++p;
				}
				bool match = reverse;
				for (; *p && *p != ']'; ++p)
				{
					char c0 = *p, c1 = c0;
					if (p[1] == '-' && p[2] && p[2] != ']')
					{
						p += 2;
						c1 = *p;
					}
					if (*path >= c0 && *path <= c1)
					{
						match = !reverse;
					}
				}
				if (!match || *p != ']')
					return pattern;
				++p;
				++path;
			}
			else if (*p == '*')
			{ // wildcard '*'
				while (*p == '*')
					++p;
				const char *best = 0;
				while (true)
				{
					const char *ret = internalPatternMatch(p, path);
					if (ret && ret > best)
						best = ret;
					if (*path == 0 || *path == '/')
						break;
					else
						++path;
				}
				return best;
			}
			else if (*p == '/' && *(p + 1) == '/')
			{ // the super-wildcard '//'
				while (*(p + 1) == '/')
					++p;
				const char *best = 0;
				while (true)
				{
					const char *ret = internalPatternMatch(p, path);
					if (ret && ret > best)
						best = ret;
					if (*path == 0)
						break;
					if (*path == 0 || (path = strchr(path + 1, '/')) == 0)
						break;
				}
				return best;
			}
			else if (*p == '{')
			{ // braced list {foo,bar,baz}
				const char *end = strchr(p, '}'), *q;
				if (!end)
					return 0; // syntax error in brace list..
				bool match = false;
				do
				{
					++p;
					q = strchr(p, ',');
					if (q == 0 || q > end)
						q = end;
					if (strncmp(p, path, q - p) == 0)
					{
						path += (q - p);
						p = end + 1;
						match = true;
					}
					else
						p = q;
				} while (q != end && !match);
				if (!match)
					return pattern;
			}
			else if (*p == *path)
			{
				++p;
				++path;
			} // any other character
			else
				break;
			pattern = p;
		}
		return (*path == 0 ? pattern : 0);
	}

	inline bool partialPatternMatch(const std::string &pattern, const std::string &test)
	{
		const char *q = internalPatternMatch(pattern.c_str(), test.c_str());
		return q != 0;
	}

	inline bool fullPatternMatch(const std::string &pattern, const std::string &test)
	{
		const char *q = internalPatternMatch(pattern.c_str(), test.c_str());
		return q && *q == 0;
	}

} // namespace oscpkt

#endif // OSCPKT_HH
