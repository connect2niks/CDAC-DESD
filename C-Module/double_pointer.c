//Double Pointer

#include <stdio.h>

int
main ()
{
  int i = 50;
  int *p, **dp;
  p = &i;
  dp = &p;

  printf ("\nvalue of i :%d = value of  *p :%d = value of **dp :%d \n", i,*p,**dp);
  printf ("\nvalue of &p :%p is equal to dp :%p\n", &p,dp);
  printf ("\nvalue of &i :%p is equal to p :%p\n", &i,p);

  return 0;
}
