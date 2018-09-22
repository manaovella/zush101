#include "define.h"
#include "typedef.h"

//
template void devnull(uint32 params[_BRAM_SIZE])
{
	uint32 counter = 0;
	uint32 max = params[0];
    loop: while (counter < max)
    {
    	counter++;
        params[1] = counter;
    }
}

//
void datadevnull(streamdata_t& inv, uint32 params[_BRAM_SIZE])
{
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS INTERFACE bram port=params

	devnull(params);
}

//
void phasedevnull(streamphase_t& inv, uint32 params[_BRAM_SIZE])
{
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS INTERFACE bram port=params

	devnull(params);
}

//
void masterdevnull(master_t& inv, uint32 params[_BRAM_SIZE])
{
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATA_PACK variable=inv struct_level
#pragma HLS INTERFACE axis register both port=inv
#pragma HLS INTERFACE bram port=params

	devnull(params);
}