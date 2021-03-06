#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "fpu.h"

int
main (int argc,char *argv[])
{
  union 
  {
    float as_float;
    uint32_t as_int;
  } a,b,c;
  
  if (argc < 2) 
    {
      puts ("usage: floor [f/i] [float/int]");
      return 1;      
    }

  switch (argv[1][0])
    {
    case 'f':
      a.as_float = atof (argv[2]);
      break;
    case 'i':
      a.as_int = atoi (argv[2]);
      break;
    default:
      puts ("invalid type argument.please type f or i");
      return 2;
    }
  
  printf ("case: %g\n",a.as_float);
  b.as_int = h_floor (a.as_int);
  c.as_float = floorf (a.as_float);
  printf ("expected : %d %d\n",c.as_int,c.as_int);
  printf ("as int : %d\n",b.as_int);
  printf ("as float : %g\n",b.as_float);
  
  printf ("%g\n",c.as_float);
  printf ("%x\n",c.as_int);
  printf ("%d\n",c.as_int);  
  printf ("expected :%g\nreturned :%g\n%d %d %d %d %d\n",floorf (a.as_float), b.as_float,b.as_int,a.as_int,c.as_int,a.as_int,b.as_float == c.as_float);
  return 0;  
}
