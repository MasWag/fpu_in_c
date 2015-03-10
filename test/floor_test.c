#include <stdio.h>
#include "../fpu.h"
#include "float.h"
#include "minunit.h"
#include <math.h>

char *
floorTest (void)
{
  for (uint32_t i = 0; i < UINT32_MAX; i++) 
    {
      static char str[1000];
      union {
	float f;
	uint32_t u;
      } a,c,e;
      a.u = i;
      c.u = h_floor(a.u);
      e.f = floorf(a.f);

      if (isnan (c.f) && isnan (e.f))
	continue;
	  

      mu_assert ((sprintf
		  (str,
		   "test of floor not passed!!\nexpected :%g\nreturned :%g\n%x %x %x %d",
		   e.f , c.f,c.u,a.u,e.u,a.u), str),c.u == e.u);
    }
  return NULL;
}

