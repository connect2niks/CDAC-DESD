//To demonstrate int, float, char, string, type constant.

#include<stdio.h>

int
main ()
{

  const int r = 10;
  const float t = 1.5;
  const char s[] = "Simple interest";
  float si;
  const char n = '\n';
  si = 1000 * r * t / 100;

  printf ("%s = %f", s, si);
  printf ("%c", n);
  return 0;
}
