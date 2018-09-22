#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

#include "define.h"

#ifndef __SDK
#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"
#endif

#ifdef __SDK
typedef u8 uint8;
typedef u16 uin16;
typedef u32 uint32;
typedef u64 uin64;
#else
typedef ap_uint<8>  uint8; // max:255
typedef ap_uint<16> uint16;// max:65535
typedef ap_uint<32> uint32;//
typedef ap_uint<64> uint64;
typedef ap_uint<1>  uint1; // max:1
typedef ap_uint<2>  uint2; // max:3
typedef ap_uint<3>  uint3; // max:7
typedef ap_uint<4>  uint4; // max:15
typedef ap_uint<5>  uint5; // max:31
typedef ap_uint<7>  uint7; // max:127
typedef ap_uint<10> uint10;// max:1023
typedef ap_uint<12> uint12;// max:4095
typedef ap_uint<13> uint13;// max:8191
typedef ap_uint<14> uint14;// max:16383
typedef ap_uint<15> uint15;// max:32767
typedef ap_uint<24> uint24;//
typedef ap_ufixed<24,12> ufixed24d12; // [0:4096.0[
typedef ap_ufixed<32,12> ufixed32d20; // [0:4096.0[
typedef ap_fixed<24,2>   fixed24d02;  // ]-2.0:2.0[
typedef ap_ufixed<32,8>  ufixed32d08; // [0:256.0[
typedef ap_fixed<32,2>   fixed32d02; //  ]-1.0:1.0[
typedef ap_uint<24> 	 i2s_t;
#endif

#ifndef __SDK


//
struct test_t
{
	uint24 phase;
	uint3  voice;
	uint3  layer;
	uint2  pan;
};

//
struct phase_t
{
	ufixed24d12 phase;
	uint4  voice;
	uint3  layer;
};

//
struct data_t
{
	fixed24d02 data;
	uint4 voice;
	uint3 layer;
};

//
struct layer_t
{
	fixed24d02 data;
	uint3 layer;
};

//
struct master_t
{
	fixed24d02 data;
	uint1 pan;
};



typedef hls::stream<i2s_t>  streami2s_t;

typedef hls::stream<test_t>  streamtest_t;

typedef hls::stream<phase_t> streamphase_t;

typedef hls::stream<data_t>  streamdata_t;

typedef hls::stream<layer_t>  streamlayer_t;

typedef hls::stream<master_t>  streammaster_t;
#endif

#endif
