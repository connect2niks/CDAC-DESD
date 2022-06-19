//Display three-dimensional array elements with addresses

#include <stdio.h>
int
main ()
{
  int a[2][3][2];

  printf ("Enter 12 values: \n");

  for (int i = 0; i < 2; ++i)
    {
      for (int j = 0; j < 3; ++j)
	{
	  for (int k = 0; k < 2; ++k)
	    {
	      scanf ("%d", &a[i][j][k]);
	    }
	}
    }

  printf ("\nElements of 3D array:\n");
  for (int i = 0; i < 2; ++i)
    {
      for (int j = 0; j < 3; ++j)
	{
	  for (int k = 0; k < 2; ++k)
	    {
	      printf ("a[%d][%d][%d] = %d and address is %p\n", i, j, k,
		      a[i][j][k], &a[i][j][k]);
	    }
	}
    }

  return 0;
}
