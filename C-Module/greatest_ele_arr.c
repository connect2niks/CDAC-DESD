#include <stdio.h>
int
main ()
{
  int n;
  double arr[100];
  printf ("Enter the number of elements (1 to 100): ");
  scanf ("%d", &n);

  for (int i = 0; i < n; ++i)
    {
      scanf ("%lf", &arr[i]);
    }

  for (int i = 1; i < n; ++i)
    {
      if (arr[0] < arr[i])
	{
	  arr[0] = arr[i];
	}
    }

  printf ("Greatest element = %.2lf\n", arr[0]);

  return 0;
}