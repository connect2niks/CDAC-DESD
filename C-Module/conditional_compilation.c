#include <stdio.h>
#define CONCAT( a, b) a ## b
#define ADD 1
#define MUL 2
#define CAL ADD

int
main ()
{
  printf ("concatenation 10 & 20 :%d\n", CONCAT (10, 20));

#if CAL == MUL
  int a, b, c;
  printf ("Enter two no. for multiplication :");
  scanf ("%d %d", &a, &b);
  c = a * b;
  printf ("Multiplication is :%d\n", c);

#elif CAL == ADD
  int x, y, z;
  printf ("Enter two no. for addition :");
  scanf ("%d %d", &x, &y);
  z = x + y;
  printf ("Addition is :%d\n", z);

#endif
  return 0;

}
