#pragma once

#define GPIO_BASE XPAR_GPIO_0_BASEADDR
#define GPIO_ID XPAR_GPIO_0_DEVICE_ID

#define LED_CHANNEL 1
#define SWITCH_CHANNEL 2


class Gpio
{
  private:
    XGpio Gpio;

  public:
  
    uint8_t init()
    {
        int Status = XGpio_Initialize(&Gpio, GPIO_ID);
        if (Status != XST_SUCCESS)
            return XST_FAILURE;

        XGpio_SetDataDirection(&Gpio, SWITCH_CHANNEL, 0xFF);
        XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);

        return XST_SUCCESS;
    }

    u32 write()
    {
        /* Write step size value to the LEDs */
        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, step);
    }

    u32 read()
    {
        step = XGpio_DiscreteRead(&Gpio, SWITCH_CHANNEL);
    }
};