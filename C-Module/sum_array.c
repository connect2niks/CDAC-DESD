//Write a C program to find the sum of all array elements

#include<stdio.h>

int
main ()
{
  int a[100], n, i, s = 0;

  printf ("Enter array size\n");
  scanf ("%d", &n);

  printf ("Enter array elements\n");
  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);

  for (i = 0; i < n; i++)
    s = s + a[i];

  printf ("Sum of the array = %d\n", s);

  return 0;
}
