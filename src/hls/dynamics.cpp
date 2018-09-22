#include "define.h"
#include "typedef.h"

fixed24d02 lut(fixed24d02 in, fixed32d02 params[_BRAM_SIZE])
{
	return params[in.to_uint()];
}

void dynamics(streamdata_t* inv, streamdata_t* outv, fixed32d02 params[_BRAM_SIZE])
{
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS DATA_PACK variable=outv struct_level
#pragma HLS INTERFACE axis register both port=outv
#pragma HLS INTERFACE bram port=params

	data_t tmp = inv->read();
	tmp.data = lut(tmp.data, params);
	outv->write(tmp);
}
