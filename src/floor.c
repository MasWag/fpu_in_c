#include <stdint.h>
#include "float.h"

uint32_t
h_floor (uint32_t in)
{
  const uint8_t sign = bin (in,31);
  const uint8_t expr = bina (in,30,23);

  uint32_t mantissa = bina (in,22,0);
  if (sign == 0) 
    {
      if (expr < 127) 
	return makeFloat(sign, 0, 0);

      if (expr <= 150)
	mantissa &= ~((1 << (23 - (expr - 127))) - 1);
    }
  else
    {
      if (expr < 127) 
	{
	  if (mantissa || expr)
	    return makeFloat(sign, 127, 0);
	  else
	    return makeFloat(sign, 0, 0);
	}
      
      if (expr <= 150)
	{
	  uint32_t tmp_mantissa = mantissa & ~((1 << (23 - (expr - 127))) - 1);
	  if (bina (mantissa,(22 - (expr - 127)),0))
	    {
	      mantissa = tmp_mantissa + (1 << (23 - (expr - 127)));
	    }
	  else
	    mantissa = tmp_mantissa;
	}
    }
  
  return makeFloat(sign, expr, mantissa);
}
