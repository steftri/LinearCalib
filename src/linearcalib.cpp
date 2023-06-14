
#include "linearcalib.h"



LinearCalib::LinearCalib(const float f32_m, const float f32_n)
  : mf32_m{f32_m}
  , mf32_n{f32_n}
{
}



void LinearCalib::setParams(const float f32_m, const float f32_n)
{
  mf32_m = f32_m;
  mf32_n = f32_n;
}



int LinearCalib::setParams(const float f32_InMin, const float f32_InMax, const float f32_OutMin, const float f32_OutMax)
{
  if(0.0==(f32_InMax-f32_InMin))  // check for division by zero
  {
    mf32_m = 1.0;
    mf32_n = f32_OutMin-f32_InMin;
    return -1; 
  }

  mf32_m = (f32_OutMax-f32_OutMin)/(f32_InMax-f32_InMin);
  mf32_n = f32_OutMin-mf32_m*f32_InMin;

  return 0;
}



void LinearCalib::getParams(float *pf32_m, float *pf32_n)
{
  if(pf32_m)
    *pf32_m = mf32_m;
  if(pf32_n)
    *pf32_n = mf32_n;
}



float LinearCalib::calc(const float f32_Value)
{
  return mf32_m*f32_Value+mf32_n;
}



float LinearCalib::map(const float f32_Value, const float f32_InMin, const float f32_InMax, const float f32_OutMin, const float f32_OutMax)
{
  if(0.0==(f32_InMax-f32_InMin))  // check for division by zero
    return f32_Value;   // shit in, shit out
  return (f32_Value-f32_InMin)*(f32_OutMax-f32_OutMin)/(f32_InMax-f32_InMin)+f32_OutMin;
}

