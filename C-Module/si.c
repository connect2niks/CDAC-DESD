/*Develop a C program to calculate simple interest using the formula I=PTR/100*/

#include<stdio.h>
void
main ()
{

  int r, p, t;
  float si;

  printf ("Enter the principle amount\n");
  scanf ("%d", &p);

  printf ("Enter the rate at which S.I has to be calculated\n");
  scanf ("%d", &r);

  printf ("Enter time in years\n");
  scanf ("%d", &t);

  si = p * r * t / 100;
  printf ("Simple Interest=%f\n", si);

}
