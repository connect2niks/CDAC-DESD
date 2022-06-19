#include<stdio.h>
void
main ()
{
  printf ("%%4f: %4f\n", 12.4321);
  printf ("%%8.5f: %8.5f\n", 1.234);
  printf ("%%.1f: %4.1f\n", 12.4321);
  printf ("%%.3f: %.3f\n", 12.4321);
  printf ("%%.3f: %.3f\n%%.3g: %.3g\n%%.3f: %.3f\n%%.3g: %.3g\n", 100.2,
	  100.2, 3.1415926, 3.1415926);
  printf ("%%.5s: %.5s\n", "abcdefg");
}
