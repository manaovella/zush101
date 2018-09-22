#pragma once

class Mem {
    void in32()
    {
        in_left = Xil_In32(I2S_DATA_RX_L_REG);
    }

    void out32()
    {
        Xil_Out32(I2S_DATA_TX_L_REG, out_left);
    }
};