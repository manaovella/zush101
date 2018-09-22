#pragma once

#define NCO_ID XPAR_NCO_0_DEVICE_ID

class Nco
{
  private:
    XNco Nco;

  public:

    //
    uint8_t init()
    {
        xil_printf("Nco::init... \r\n");
        XNco_Config *cfgPtr = XNco_LookupConfig(NCO_ID);
        if (!cfgPtr)
        {
            xil_printf("ERROR: Lookup of NCO configuration failed.\n\r");
            return XST_FAILURE;
        }

        int status = XNco_CfgInitialize(&Nco, cfgPtr);
        if (status != XST_SUCCESS)
        {
            xil_printf("ERROR: Could not initialise NCO.\n\r");
            return XST_FAILURE;
        }

        xil_printf("...Nco::init \r\n");
        return XST_SUCCESS;
    }

    //
    void setStep()
    {
        /* Input scaled step size to the NCO core */
        XNco_SetStep_size_v(&Nco, nco_in);
    }

    //
    u32 getSineSample()
    {
        /* Receive sinusoidal sample from NCO core */
        nco_out = XNco_GetSine_sample_v(&Nco);
    }
};