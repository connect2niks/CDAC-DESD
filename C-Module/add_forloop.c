//Develop a C program which adds all numbers from 1 to N, except those which are divisible by 5. Implement this using for loop and continue statement.

#include<stdio.h>

int main ()
{
  int i, n, j = 0;

  printf ("Enter the n numbers:");
  scanf ("%d", &n);

  for (i = 1; i <= n; i++)
    {

      if (i % 5 == 0)
	{
	  continue;

	}
      j = j + i;
    }

  printf ("addition is = %d\n", j);

  return 0;
}
