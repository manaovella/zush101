#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

class UdpServer
{
	private:

		int port;
		int enabled;
		int inSocket;
		struct sockaddr_in server;
		struct timeval stTimeOut;
		struct timeval stZeroTimeOut;
		fd_set stReadFDS;
		int size;
		void *wasteBuffer;
		int wasteBufferSize;
		int length;
		socklen_t fromLength;
		struct sockaddr_in from;

	public:

		UdpServer();
		UdpServer(int aPort);
		~UdpServer();
		bool init(int aPort);
		bool bindToPort(int aPort);
		int getBoundPort() const;
		int read(void* destBuffer, int maxBytesToRead, bool blockUntilSpecifiedAmountHasArrived);
		void close();
		int empty();
		int empty(int maxCount);
		int waitUntilReady(bool readyForReading, int timeoutMsecs);
};

#endif /* UDPSERVER_H_ */
