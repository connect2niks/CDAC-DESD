//arrange array elements in ascending order

#include <stdio.h>
void
main ()
{

  int i, j, a, n, arr[50];
  printf ("Enter the no. of elements of array \n");
  scanf ("%d", &n);
  printf ("Enter the elements :");
  for (i = 0; i < n; ++i)
    scanf ("%d\n", &arr[i]);
  for (i = 0; i < n; ++i)
    {
      for (j = i + 1; j < n; ++j)
	{
	  if (arr[i] > arr[j])
	    {

	      a = arr[i];
	      arr[i] = arr[j];
	      arr[j] = a;
	    }
	}
    }

  printf ("Numbers arranged in ascending order :\n");
  for (i = 0; i < n; ++i)
    printf ("%d\t", arr[i]);

}
