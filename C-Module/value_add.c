//display value and address of 2D array

#include<stdio.h>
int
main ()
{

  int arr[2][3];
  int i, j;
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("Enter value for arr[%d][%d]:", i, j);
	  scanf ("%d", &arr[i][j]);
	}
    }
  printf ("\n2D array elements:\n");
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%d ", arr[i][j]);
	}
    }

  printf ("\n2D array elements address :\n");
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%p ", &arr[i][j]);
	}
    }

  return 0;
}
