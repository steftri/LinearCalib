
#ifndef _LIN_CALIB_H_
#define _LIN_CALIB_H_

#include <inttypes.h>


class LinearCalib
{
  float mf32_m;
  float mf32_n;

public:
  LinearCalib(const float f32_m = 1.0, const float f32_n = 0.0);

  void setParams(const float f32_m, const float f32_n);
  int  setParams(const float f32_InMin, const float f32_InMax, const float f32_OutMin, const float f32_OutMax);
  void getParams(float *pf32_m, float *pf32_n);

  float calc(const float f32_Value);

  static float map(const float f32_Value, const float f32_InMin, const float f32_InMax, const float f32_OutMin, const float f32_OutMax);
};


#endif // _LIN_CALIB_H_
