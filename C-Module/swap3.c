// Write a program to perform the swap operation, Write a swap function and use call by reference

#include<stdio.h>
void swap (int *i, int *j);

void
main ()
{
  int a, b;
  printf ("enter value of a and b :\n");
  scanf ("%d%d", &a, &b);
  swap (&a, &b);
  printf ("final value of a and b after swapping :%d %d\n", a, b);

}

void
swap (int *i, int *j)
{
  int t;
  t = *i;
  *i = *j;
  *j = t;
}
