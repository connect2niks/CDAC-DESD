//Develop a C program to find sum of all odd numbers upto N using while loop

#include <stdio.h>
int
main ()
{

  int n, i = 1, j = 0;
  printf ("Enter n value:");
  scanf ("%d", &n);
  while (i <= n)
    {
      if (i % 2 != 0)
	{
	  j = j + i;

	}

      i++;
    }
  printf ("addition of odd no. is:%d", j);
  return 0;
}
