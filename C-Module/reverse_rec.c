//Reverse using recursive function

#include <stdio.h>

int
main ()
{
  int n, r;
  printf ("enter any number :");
  scanf ("%d", &n);
  r = reverse (n);		//function call
  printf ("\n After reverse :%d\n", r);
  return 0;
}

int s = 0, rem;
reverse (int n)
{

  if (n)
    {
      rem = n % 10;
      s = s * 10 + rem;
      reverse (n / 10);		//function calling in function itself
    }
  else
    return s;
}
