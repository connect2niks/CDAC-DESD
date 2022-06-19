//Write a program to find the area and the perimeter of a circle

#include<stdio.h>
void
main ()
{

  float ar, r, pr;

  printf ("enter radius for find its area\n");
  scanf ("%f", &r);
  ar = 3.14 * r * r;
  pr = 2 * 3.14 * r;
  printf ("Area of circle is=%f and perimeter of circle is %f\n", ar, pr);

}
