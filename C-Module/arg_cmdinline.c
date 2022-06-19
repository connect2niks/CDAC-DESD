//Write a program to find the smallest and greatest integers among all integers, which are provided through the command line.

#include <stdio.h>
#include <stdlib.h>
int
main (int c, char *v[])
{

  int i;
  int l = atoi (v[1]), s = atoi (v[1]);
  for (i = 1; i < c; i++)
    {
      if (atoi (v[i]) > l)
	l = atoi (v[i]);

      if (atoi (v[i]) < s)
	s = atoi (v[i]);
    }
  printf ("Greatest integer:%d\n", l);
  printf ("Smallest integer:%d\n", s);

  return 0;
}
