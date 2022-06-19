// Copy one array to another array 

#include<stdio.h>

int
main ()
{
  int i, j, a[2][3] = { 75, 82, 53, 94, 85, 76 }, b[2][3];

  printf ("Element of 1st array are :\n");


  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{

	  printf ("a[%d][%d]...%d\n", i, j, a[i][j]);
	  b[i][j] = a[i][j];

	}

    }

  printf ("Element of 2nd array are :\n");

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{

	  printf ("b[%d][%d]...%d\n", i, j, b[i][j]);

	}

    }

  return 0;
}
