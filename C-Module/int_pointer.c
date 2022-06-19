//WAP to declare an integer and an integer pointer to it. Initialize the integer variable. Print the value of the int variable using pointer variable.

#include <stdio.h>
void
main ()
{

  int i;
  int *j;
  i = 100;
  j = &i;
  printf ("value of int variable using pointer variable :%d\n", *j);



}
