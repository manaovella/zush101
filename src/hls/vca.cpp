#include "define.h"
#include "typedef.h"

// #define _DEBUG

#define _IDX_VOICECOEFF 0
#define _IDX_ACC        _MAX_VOICESLAYERS + _MAX_LAYERS

//
void vca(streamdata_t* inv, streamlayer_t* outv, ufixed32d08 params[_BRAM_SIZE])
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=outv
#pragma HLS DATA_PACK variable=outv struct_level
#pragma HLS INTERFACE bram port=params
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM

	//
	for (int i = 0; i < _MAX_VOICESLAYERS; i++)
	{
		data_t tmp = inv->read();
		fixed24d02 dt = tmp.data;
		uint3 voice = tmp.voice;
		uint3 layer = tmp.layer;

		params[_IDX_ACC + layer] = params[_IDX_ACC + layer] + dt * params[voice + layer * _MAX_VOICES];
	}

	//
	for (int j = 0; j < _MAX_LAYERS; j++)
	{
		layer_t ret;
		ret.data = params[_IDX_ACC + j];
		outv->write(ret);
	}
}

i2s_t toi2s(fixed24d02 val)
{
	return (i2s_t)(val *_MAXVAL24BIT);
}

//
void vcamaster(streamlayer_t* inv, streami2s_t* outv, ufixed32d08 params[_BRAM_SIZE])
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=outv
#pragma HLS DATA_PACK variable=outv struct_level
#pragma HLS INTERFACE bram port=params
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM

	//
	fixed24d02 acc = 0;
	for (int i = 0; i < _MAX_LAYERS; i++)
	{
		layer_t tmp = inv->read();
		acc += tmp.data * params[i];
	}

	outv->write(toi2s(acc));
}
