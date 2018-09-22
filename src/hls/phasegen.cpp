#include "define.h"
#include "typedef.h"

// #define _DEBUG

#define _IDX_PHASEINC 		0
#define _IDX_PHASECURR		_MAX_VOICESLAYERS
#define _IDX_CURRVOICE	2 * _MAX_VOICESLAYERS
#define _IDX_CURRLAYER	2 * _MAX_VOICESLAYERS + 1

//
void phasegen(streamphase_t& outval, ufixed32d20 params[_BRAM_SIZE])
{
#pragma HLS DATA_PACK variable=outval struct_level
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE bram port=params
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=outval

#ifndef _DEBUG
	//
	uint3 currvoice = params[_IDX_CURRVOICE];
	uint3 currlayer = params[_IDX_CURRLAYER];

	params[_IDX_CURRVOICE] = (currvoice + 1) % _MAX_VOICES;
	params[_IDX_CURRLAYER] = (currlayer + 1) % _MAX_LAYERS;

	int idx = currvoice + currlayer * _MAX_VOICES;
	ufixed32d20 currphase = params[idx + _IDX_PHASECURR];
	currphase += params[idx];
	params[idx] = currphase;

	phase_t val;
	val.phase = currphase;
	val.layer = currlayer;
	val.voice = currvoice;
#else
	phase_t val;
	val.phase = params[0];
	val.layer = 7;
	val.voice = 7;
#endif

	outval.write(val);
}
