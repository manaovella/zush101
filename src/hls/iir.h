#ifndef __IIR_H__
#define __IIR_H__

void iir(streamdata_t* input,
         streamdata_t* output, 
         unsigned int coeffin[_FIRIN_LENGTH], 
         unsigned int coeffout[_FIROUT_LENGTH])
{
    //
    for (int i = 0; i < _FIR_LENGTH - 1; i++)
        in_store[i] = in_store[i + 1];

    in_store[_FIR_LENGTH - 1] = input->read();

    //
    unsigned int acc = 0; 
    for (int i = 0; i < _FIR_LENGTH; i++)
        acc += in_store[i] * coeff[i];

    output->write((data_t)(acc >> _BITS_FIR);
}

#endif