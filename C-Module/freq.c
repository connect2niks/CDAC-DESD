//Frequency of each element in array

#include <stdio.h>
int
main ()
{
  int a[100], b[100];
  int i, j, s, c;
  printf ("Enter size of array :");
  scanf ("%d", &s);
  printf ("Enter elements of array :");
  for (i = 0; i < s; i++)
    {
      scanf ("%d", &a[i]);
      b[i] = 1;
    }
  for (i = 0; i < s; i++)
    {
      c = 1;
      for (j = i + 1; j < s; j++)
	{
	  if (a[i] == a[j])
	    {

	      c++;
	      b[j] = 0;

	    }


	}

      if (b[i] != 0)
	{
	  b[i] = c;
	}

    }
  printf ("\nFrequency of all elements of array :\n");
  for (i = 0; i < s; i++)
    {
      if (b[i] != 0)
	{
	  printf ("%d occurs %d times\n", a[i], b[i]);

	}

    }

  return 0;
}
