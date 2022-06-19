//for removing the duplicate element

#include <stdio.h>
int
main ()
{

  int arr[50], i, j, k, s;

  printf (" Enter the number of elements in an array: ");
  scanf (" %d", &s);

  printf (" \n Enter %d elements of an array: \n ", s);

  for (i = 0; i < s; i++)
    {
      scanf (" %d", &arr[i]);
    }

  for (i = 0; i < s; i++)
    {
      for (j = i + 1; j < s; j++)
	{

	  if (arr[i] == arr[j])
	    {
	      for (k = j; k < s - 1; k++)
		{
		  arr[k] = arr[k + 1];
		}
	      s--;

	      j--;
	    }
	}
    }


  printf (" \n Array elements after deletion of the duplicate elements: ");

  for (i = 0; i < s; i++)
    {
      printf (" %d \t", arr[i]);
    }
  return 0;
}
