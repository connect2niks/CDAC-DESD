//Develop a C program to add two operands and store the result in one of the operand using addition assignment operator.( a+=b is same as a=a+b)

#include <stdio.h>
void
main ()
{
  int a, b;
  printf ("enter two no.\n");
  scanf ("%d%d", &a, &b);
  a += b;
  printf ("a=%d\n", a);
  a -= b;
  printf ("a=%d\n", a);
  a *= b;
  printf ("a=%d\n", a);
  a /= b;
  printf ("a=%d\n", a);
}
