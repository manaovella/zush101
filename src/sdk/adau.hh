#pragma once

#include "define.h"
#include "audiodef.h"

class Adau
{
  private:
    XIicPs Iic;

    //
    void wait()
    {
        while (XIicPs_BusIsBusy(&Iic))
        {
        }
    }

    //
    void WriteToReg(unsigned char u8RegAddr, unsigned char u8Data)
    {
        unsigned char u8TxData[3] = {0x40, u8RegAddr, u8Data};
        XIicPs_MasterSendPolled(&Iic, u8TxData, 3, (IIC_SLAVE_ADDR >> 1));
        wait();
    }

    //
    void PollPllLockBit()
    {
        unsigned char u8TxData[8], u8RxData[6];
        // Register address set: 0x4002
        u8TxData[0] = 0x40;
        u8TxData[1] = 0x02;

        // Poll PLL Lock bit
        do
        {
            XIicPs_MasterSendPolled(&Iic, u8TxData, 2, (IIC_SLAVE_ADDR >> 1));
            wait();
            XIicPs_MasterRecvPolled(&Iic, u8RxData, 6, (IIC_SLAVE_ADDR >> 1));
            wait();
        } while ((u8RxData[5] & 0x02) == 0); // while not locked
    }

    //
    uint8_t pllConfig()
    {
        int Status;

        Status = IicConfig(XPAR_XIICPS_0_DEVICE_ID);
        if (Status != XST_SUCCESS)
        {
            xil_printf("\nError initializing IIC");
            return XST_FAILURE;
        }

        WriteToReg(R0_CLOCK_CONTROL, 0x0E);
        u8TxData[0] = {0x40, 0x02, 0x02, 0x71, 0x02, 0x3C, 0x21, 0x01};
        XIicPs_MasterSendPolled(&Iic, u8TxData, 8, (IIC_SLAVE_ADDR >> 1));
        wait();
        PollPllLockBit();
        WriteToReg(R0_CLOCK_CONTROL, 0x0F);
    }

    //
    void AudioConfigureJacks()
    {
        WriteToReg(R4_RECORD_MIXER_LEFT_CONTROL_0, 0x01);
        WriteToReg(R5_RECORD_MIXER_LEFT_CONTROL_1, 0x07);
        WriteToReg(R6_RECORD_MIXER_RIGHT_CONTROL_0, 0x01);
        WriteToReg(R7_RECORD_MIXER_RIGHT_CONTROL_1, 0x07);
        WriteToReg(R19_ADC_CONTROL, 0x13);
        WriteToReg(R22_PLAYBACK_MIXER_LEFT_CONTROL_0, 0x21);
        WriteToReg(R24_PLAYBACK_MIXER_RIGHT_CONTROL_0, 0x41);
        WriteToReg(R26_PLAYBACK_LR_MIXER_LEFT_LINE_OUTPUT_CONTROL, 0x05);
        WriteToReg(R27_PLAYBACK_LR_MIXER_RIGHT_LINE_OUTPUT_CONTROL, 0x11);
        WriteToReg(R29_PLAYBACK_HEADPHONE_LEFT_VOLUME_CONTROL, 0xFF);
        WriteToReg(R30_PLAYBACK_HEADPHONE_RIGHT_VOLUME_CONTROL, 0xFF);
        //WriteToReg(R31_PLAYBACK_LINE_OUTPUT_LEFT_VOLUME_CONTROL, 0xE6);
        //WriteToReg(R32_PLAYBACK_LINE_OUTPUT_RIGHT_VOLUME_CONTROL, 0xE6);
        WriteToReg(R31_PLAYBACK_LINE_OUTPUT_LEFT_VOLUME_CONTROL, 0xFE);
        WriteToReg(R32_PLAYBACK_LINE_OUTPUT_RIGHT_VOLUME_CONTROL, 0xFE);
        WriteToReg(R35_PLAYBACK_POWER_MANAGEMENT, 0x03);
        WriteToReg(R36_DAC_CONTROL_0, 0x03);
        WriteToReg(R58_SERIAL_INPUT_ROUTE_CONTROL, 0x01);
        WriteToReg(R59_SERIAL_OUTPUT_ROUTE_CONTROL, 0x01);
        WriteToReg(R65_CLOCK_ENABLE_0, 0x7F);
        WriteToReg(R66_CLOCK_ENABLE_1, 0x03);
    }

    //
    void LineinLineoutConfig()
    {
        WriteToReg(R17_CONVERTER_CONTROL_0, 0x05);
        WriteToReg(R64_SERIAL_PORT_SAMPLING_RATE, 0x05);
        WriteToReg(R19_ADC_CONTROL, 0x13);
        WriteToReg(R36_DAC_CONTROL_0, 0x03);
        WriteToReg(R35_PLAYBACK_POWER_MANAGEMENT, 0x03);
        WriteToReg(R58_SERIAL_INPUT_ROUTE_CONTROL, 0x01);
        WriteToReg(R59_SERIAL_OUTPUT_ROUTE_CONTROL, 0x01);
        WriteToReg(R65_CLOCK_ENABLE_0, 0x7F);
        WriteToReg(R66_CLOCK_ENABLE_1, 0x03);
        WriteToReg(R4_RECORD_MIXER_LEFT_CONTROL_0, 0x01);
        WriteToReg(R5_RECORD_MIXER_LEFT_CONTROL_1, 0x05);
        WriteToReg(R6_RECORD_MIXER_RIGHT_CONTROL_0, 0x01);
        WriteToReg(R7_RECORD_MIXER_RIGHT_CONTROL_1, 0x05);
        WriteToReg(R22_PLAYBACK_MIXER_LEFT_CONTROL_0, 0x21);
        WriteToReg(R24_PLAYBACK_MIXER_RIGHT_CONTROL_0, 0x41);
        WriteToReg(R26_PLAYBACK_LR_MIXER_LEFT_LINE_OUTPUT_CONTROL, 0x03);  //0 dB
        WriteToReg(R27_PLAYBACK_LR_MIXER_RIGHT_LINE_OUTPUT_CONTROL, 0x09); //0 dB
        WriteToReg(R29_PLAYBACK_HEADPHONE_LEFT_VOLUME_CONTROL, 0xE7);      //0 dB
        WriteToReg(R30_PLAYBACK_HEADPHONE_RIGHT_VOLUME_CONTROL, 0xE7);     //0 dB
        WriteToReg(R31_PLAYBACK_LINE_OUTPUT_LEFT_VOLUME_CONTROL, 0xE6);    //0 dB
        WriteToReg(R32_PLAYBACK_LINE_OUTPUT_RIGHT_VOLUME_CONTROL, 0xE6);   //0 dB
    }

  public:

    //
    unsigned char init()
    {
        XIicPs_Config *Config;
        int Status;

        /* Initialise the IIC driver so that it's ready to use */

        // Look up the configuration in the config table
        Config = XIicPs_LookupConfig(DeviceIdPS);
        if (NULL == Config)
            return XST_FAILURE;

        // Initialise the IIC driver configuration
        Status = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
        if (Status != XST_SUCCESS)
            return XST_FAILURE;

        //Set the IIC serial clock rate.
        XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);

        return XST_SUCCESS;
    }
}