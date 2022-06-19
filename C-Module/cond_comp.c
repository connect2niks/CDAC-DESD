#include <stdio.h>
#define INT 1
#define FLOAT 2
#define CAL  FLOAT


int
main ()
{

#if CAL == INT
  int a, b, c;
  printf ("Enter two integers :");
  scanf ("%d %d", &a, &b);
  c = a + b;
  printf ("Addition of two integers is :%d\n", c);

#elif CAL == FLOAT

  float d, e, f;
  printf ("Enter two float values :");
  scanf ("%f %f", &d, &e);
  f = d + e;
  printf ("Addition of two float values is :%f\n", f);

#endif
  return 0;
}
