// swap function

#include <stdio.h>

int
main ()
{
  int x, y;
  printf ("Enter Value of x :");
  scanf ("%d", &x);
  printf ("\nEnter Value of y :");
  scanf ("%d", &y);

  int t = x;
  x = y;
  y = t;

  printf ("\nAfter Swapping: x=%d,y=%d\n", x, y);
  return 0;
}
