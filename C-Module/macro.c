#include<stdio.h>
#define RADIUS 3

int
main ()
{

  float vol, pi = 3.14;

  vol = (4.0 / 3.0) * pi * (RADIUS * RADIUS * RADIUS);
  printf ("Volume of sphere is :%f\n", vol);
  return 0;
}
