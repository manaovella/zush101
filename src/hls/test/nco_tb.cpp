#include "stdio.h"
#include <string.h>
#include "math.h"

#include "ap_fixed.h"

#define _RUNS 1024
#define _STEP 20.79

void nco(ap_fixed<16,2>* sine_sample, ap_ufixed<16,12> step_size);

int main()
{
    FILE* fp;
    ap_fixed<16,2> output;
    ap_ufixed<16,12> step = _STEP;

    int i = 0; 

    char* outfile = "c:\\zynq\nco_sine.m";

    fp = fopen(outfile, "w");
    if (!fp)
    {
        printf(stderr, "can't");
    }

    for (int i = 0; i < _RUNS; i++)
    {
        nco(&output, step);
    }    
}
