#ifndef __DEFINE_H__
#define __DEFINE_H__

#define _FCLK0 196608000
#define _FCLK2 200000000
#define _FCLK3 12288000
#define _FS    48000
#define _FS2   _FS >> 1
#define _COEFFWAVE 65535 * 1024 / 48000

#define _DIVIDER  _FCLK0 / _FS
#define _DIVIDER3 _FCLK3 / _FS

#define _BITS_DATA      24
#define _BITS_VOICES    3
#define _MAX_VOICES  8
#define _BITS_LAYERS    3
#define _MAX_LAYERS  8
#define _BITS_LAST      2    
#define _BITS_PAN       1
#define _MAX_VOICESLAYERS _MAX_VOICES * _MAX_LAYERS
#define SAMPLESWAV _FS

#define _MAXVAL16BIT 65535
#define _MAXVAL24BIT 16777215

#define _MAX_COEFF 255
#define _BRAM_SIZE 1024

#define _PAN_LEFT   0
#define _PAN_RIGHT  1

#endif
