#include <stdio.h>
int fibonacci (int i);
int
main ()
{

   int i,m = 1;

 // printf ("Enter range :");
  //scanf ("%d", &n);
  for (i = 3; i < 10; i++)
    {
   int v = fibonacci(i);
      for (int j = 2; j < v; j++)
	{
	  if (v%j==0)
	    {
	      m = 0;
	      break;
	    }

	}

      if (m == 1)
	{
	  printf ("%d\t",v);
	}
       }
      return 0;
    }

   
  int fibonacci (int i)
  {

    if (i == 0) return 0;
    if (i == 1) return 1;
    return (fibonacci (i - 1) + fibonacci (i - 2));

  }
