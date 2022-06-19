//Sum of 2D Matrices

#include <stdio.h>
int
main ()
{
  int a, b, c, d, a1[10][10], a2[10][10], s[10][10];

  printf
    ("Enter the number of rows and columns of matrix for both matrices\n");
  scanf ("%d %d", &a, &b);

  printf ("Enter %d elements of first matrix\n", a * b);
  for (c = 0; c < a; c++)
    for (d = 0; d < b; d++)
      {
	scanf ("%d", &a1[c][d]);
      }
  printf ("Enter %d elements of second matrix\n", a * b);

  for (c = 0; c < a; c++)

    for (d = 0; d < b; d++)
      {
	scanf ("%d", &a2[c][d]);
      }
  printf ("Sum of entered matrices:-\n");

  for (c = 0; c < a; c++)
    {
      for (d = 0; d < b; d++)
	{
	  s[c][d] = a1[c][d] + a2[c][d];
	  printf ("%d\t", s[c][d]);
	}
      printf ("\n");
    }
  return 0;
}
