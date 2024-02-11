#include "quadraticroots.h"
#include <math.h>

QuadraticRootsResult findroots  (long double a,long double b,long double c)
{
  QuadraticRootsResult result;
  long double D = b*b-4*a*c;
  if(D>=0)
  {
      result.x1=(-b-sqrtl(D))/(2*a);
      result.x2=(-b+sqrtl(D))/(2*a);
      result.norealroots=0;
  }
  else
  {
      result.x1=0;
      result.x2=0;
      result.norealroots=1;
  }
  return result;
}