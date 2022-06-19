//Write a program to demonstrate bitwise operators

#include <stdio.h>
int
main ()
{
  int a, b, c, d, e, f, g, i, k, l;

  printf ("enter two values for bitwise and operator\n");
  scanf ("%d%d", &a, &b);
  printf ("output = %d\n", a & b);

  printf ("enter two values for bitwise or operator\n");
  scanf ("%d%d", &c, &d);
  printf ("output = %d\n", c | d);

  printf ("enter two values for bitwise xor operator\n");
  scanf ("%d%d", &e, &f);
  printf ("output = %d\n", e ^ f);

  printf ("enter a value for right shift");
  scanf ("%d", &g);
  for (k = 1; k <= 2; ++k)
    printf ("Right shift by %d: %d\n", k, g >> k);

  printf ("enter a value for left shift");
  scanf ("%d", &i);
  for (l = 1; l <= 2; ++l)
    printf ("left shift by %d: %d\n", l, i << l);

  return 0;

}
