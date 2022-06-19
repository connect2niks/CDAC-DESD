//Write a C program to find the maximum of 2 numbers using Conditional operator.

#include<stdio.h>
void
main ()
{
  int a, b, c;
  printf ("enter two no.");
  scanf ("%d%d", &a, &b);
  c = a > b ? a : b;
  printf ("max. value=%d", c);

}
