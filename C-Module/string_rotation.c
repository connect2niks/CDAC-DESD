//Write a program to print out all rotations of a string typed in

#include<stdio.h>
int main()
{
  char a[100];
  int i, j;
  printf ("Enter a word: ");
  gets (a);

  for (i = 0; a[i] != 0; i++)
    {
      for (j = i; a[j] != 0; j++)
	printf ("%c", a[j]);

      for (j = 0; j < i; j++)
	printf ("%c", a[j]);
      printf ("\n");
    }

  return 0;
}
