#include "define.h"
#include "typedef.h"
#include "nco.h"
#include "sin.h"

//
void nco(streamphase_t* phasein, streamdata_t* dataout, uint32 params[_BRAM_SIZE])
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS DATA_PACK variable=phasein struct_level
#pragma HLS INTERFACE axis register both port=phasein
#pragma HLS DATA_PACK variable=dataout struct_level
#pragma HLS INTERFACE axis register both port=dataout
#pragma HLS RESOURCE variable=params core=RAM_1P_BRAM
#pragma HLS INTERFACE bram port=params

	phase_t t = phasein->read();

	data_t o;
	o.data = sinarray[t.phase.to_int() % 1024];
	o.voice = t.voice;
	o.layer = t.layer;
	dataout->write(o);
}
