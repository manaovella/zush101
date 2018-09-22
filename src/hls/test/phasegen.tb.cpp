#include "define.h"
#include "typedef.h"

void phasegen(streamphase_t& outval, uint32 params[256]);

int main()
{
	ufixed24d12 val = .2;

	streamphase_t out;
	uint32 params[256];
	params[0] = ufixed24d12 val = .2;

	for (int i = 1; i < _NUMMAX_VOICES * _NUMMAX_LAYERS; i++)
		params[0] = (uint32)((ufixed24d12)params[i-1] + val);

	for (int j = 0; j < 1000; j++)
		phasegen(out, params);

	return 0;
}
