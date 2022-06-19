//Write a program in C to store n elements(read from standard input) in an array and print the elements using pointer

#include <stdio.h>
void
main ()
{
  int a[10], i, s, *p;
  p = a;

  printf ("\nEnter the size of array :");
  scanf ("%d", &s);

  printf ("\nEnter the element of array :");
  for (i = 0; i < s; i++)
    scanf ("%d", (a + i));

  printf ("\nArray elements :\n");
  for (i = 0; i < s; i++)
    printf ("%d\n", *(a + i));



}
