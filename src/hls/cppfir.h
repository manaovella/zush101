#ifndef _CPP_FIR_H_
#define _CPP_FIR_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define N 85

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

// Class CFir definition
template <class coef_T, class data_T, class acc_T>
class CFir
{
protected:
  static const coef_T c[N];
  data_T shift_reg[N - 1];

private:
public:
  data_T operator()(data_T x);
  template <class coef_TT, class data_TT, class acc_TT>
  friend ostream &
  operator<<(ostream &o, const CFir<coef_TT, data_TT, acc_TT> &f);
};

// Load FIR coefficients
template <class coef_T, class data_T, class acc_T>
const coef_T CFir<coef_T, data_T, acc_T>::c[N] = {
#include "cpp_FIR.inc"
};

// FIR main algorithm
template <class coef_T, class data_T, class acc_T>
data_T CFir<coef_T, data_T, acc_T>::operator()(data_T x)
{
  int i;
  acc_t acc = 0;
  data_t m;

loop:
  for (i = N - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      m = x;
      shift_reg[0] = x;
    }
    else
    {
      m = shift_reg[i - 1];
      if (i != (N - 1))
        shift_reg[i] = shift_reg[i - 1];
    }
    acc += m * c[i];
  }
  return acc;
}

// Operator for displaying results
template <class coef_T, class data_T, class acc_T>
ostream &operator<<(ostream &o, const CFir<coef_T, data_T, acc_T> &f)
{
  for (int i = 0; i < (sizeof(f.shift_reg) / sizeof(data_T)); i++)
  {
    o << "shift_reg[" << i << "]= " << f.shift_reg[i] << endl;
  }
  o << "______________" << endl;
  return o;
}

data_t cpp_FIR(data_t x);

#endif