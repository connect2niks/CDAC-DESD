//Write a C program to display the pattern like right angle triangle

#include <stdio.h>
void
main ()
{
  int i, j, k, a = 1;
  printf ("Enter no. of rows");
  scanf ("%d", &j);
  for (i = 1; i <= j; i++)
    {
      for (k = 1; k <= i; k++)
	printf ("%d", a++);
      printf ("\n");

    }

}