//To search element in an (1D) array using pointer

#include <stdio.h>
int s (int, int, int *);
int i, j;
void
main ()
{
  int a, b;
  printf ("Enter the size of the array :");
  scanf ("%d", &a);
  int ar[a];
  printf ("Enter the element of array:\n");
  for (i = 0; i < a; i++)
    {
      scanf ("%d", &ar[i]);
    }
  printf ("Enter the element to be searched ");
  scanf ("%d", &b);

  s (a, b, ar);

}

int
s (int a, int b, int *ar)
{
  for (i = 0; i < a; i++)
    {
      if (b == ar[i])
	{
	  j = 1;
	  break;
	}
    }

  if (j == 1)
    {
      printf ("%d is present in array ", b);
    }

  else
    {

      printf ("%d is not present in array", b);
    }
}
