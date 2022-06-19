//Reversing the element of 1D array

#include <stdio.h>
int
main ()
{
  int n, i, j, a[100], b[100];

  printf ("Enter no of elements in array\n");
  scanf ("%d", &n);

  printf ("Enter array elements\n");

  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);

  for (i = n - 1, j = 0; i >= 0; i--, j++)
    b[j] = a[i];

  for (i = 0; i < n; i++)
    a[i] = b[i];
  printf ("The reversed array:\n");

  for (i = 0; i < n; i++)
    printf ("%d\t", a[i]);

  return 0;
}
