#include <stdio.h>
#include <xil_io.h>
#include <sleep.h>
#include "xiicps.h"
#include <xil_printf.h>
#include <xparameters.h>
#include "xgpio.h"
#include "xuartps.h"
#include "stdlib.h"
#include "audio.h"
#include "xnco.h"
#include "gpio.hh"
#include "nco.hh"


int main(void)
{
    xil_printf("Lab8-Zynq\r\n");

    // adau
    Adau adau;
    adau.init();
    adau.pllCnofig();
    adau.jackSetup();

    IicConfig();
    AudioPllConfig();
    AudioConfigureJacks();
    xil_printf("ADAU1761 configured\n\r");
    Nco nco;
    nco.init();

    Gpio gpio;
    gpio.init();

    read_superpose_play();
    return 1;
}
