//G.C.D

#include <stdio.h>
void
main ()
{
  int a, b, c, i;

  printf ("Enter two integers: ");
  scanf ("%d %d", &a, &b);

  for (i = 1; i <= a && i <= b; i++)
    {

      if (a % i == 0 && b % i == 0)
	c = i;
    }

  printf ("G.C.D of %d and %d is %d\n", a, b, c);

}
