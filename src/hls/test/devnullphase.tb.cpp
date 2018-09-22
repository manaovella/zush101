#include "stdinc.h"

void devnull(streamdata_t& invalue, uint32 cycles[256]);

int main()
{
	uint32 buf[256];
	buf[0] = 168;
	streamdata_t inv;
	data_t v;
	v.data  = 1;
	v.voice = 1;
	v.layer = 1;
	v.layerlast = 0;
	v.voicelast = 0;
	inv.write(v);
	devnull(inv, buf);
}
