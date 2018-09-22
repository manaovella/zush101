#pragma once

#define UART_BASEADDR XPAR_PS7_UART_1_BASEADDR

class Uart
{
    bool isReceiveData()
    {
        return XUartPs_IsReceiveData(UART_BASEADDR);
    }
};