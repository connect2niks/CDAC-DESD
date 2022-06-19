#include <stdio.h>

int
main ()
{

  int a[5], i;

  for (i = 0; i < 5; i++)
    {
      a[i] = i;

    }

  printf ("Array values with their addresses-\n");
  for (i = 0; i < 5; i++)
    {
      printf ("%d address is %p\n", a[i], &a[i]);

    }
  return 0;

}
