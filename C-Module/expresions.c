//Determine the value of each of the following expressions. 

#include<stdio.h>
void
main ()
{

  int i = 8, j = 5;
  int a, b, e, g;
  float x = 0.005, y = 0.01, f;
  char c = 'c', d = 'd';

  a = (3 * i * j) % (2 * d);
  printf ("value of a=%d\n", a);

  b = (i * j) % (c + 2 * d) / (x * y);
  printf ("value of b=%d\n", b);

  e = 5 * (i + j) > 'c';
  printf ("value of e=%d\n", e);

  f = 2 * x + (y == 0);
  printf ("value of f=%f\n", f);

  g = (x > y) && (i > 0) || (j < 5);
  printf ("value of g=%d\n", g);
}
