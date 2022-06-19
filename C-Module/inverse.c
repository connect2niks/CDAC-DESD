// Inverse of 2x2 matrix

#include <stdio.h>

int
main ()
{
  int a[2][2], b, i, j, d;
  float c[2][2];

  printf ("Enter element of 2x2 matrix");
  for (i = 0; i < 2; i++)
    {

      for (j = 0; j < 2; j++)
	{

	  scanf ("%d", &a[i][j]);


	}

    }

  printf ("Matrix a is \n");

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)

	{

	  printf ("%d\t", a[i][j]);
	}
      printf ("\n");
    }

//calculate determinant of matrix a

  d = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
  if (d == 0)
    {
      printf ("Deteminant can't be zero");
      return 0;
    }
//find adjoint of matrix a

  b = a[0][0];
  a[0][0] = a[1][1];
  a[1][1] = b;
  a[0][1] = -a[0][1];
  a[1][0] = -a[1][0];

//Find inverse of matrix a

  printf ("Inverse of matrix a is \n");

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)

	{

	  c[i][j] = (a[i][j]) / (float) d;
	  printf ("%.1f\t", c[i][j]);
	}
      printf ("\n");
    }
  return 0;
}
