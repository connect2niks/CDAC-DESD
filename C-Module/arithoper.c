//Develop a C program to perform operations (+,*,-, / and %) on two whole number

#include <stdio.h>
int
main ()
{
  double a, b, c;
  int d;
  printf ("Enter two whole no.\t");
  scanf ("%lf %lf", &a, &b);

  printf
    ("press 1 for Addition\npress 2 for Substration\npress 3 for Multiplication\npress 4 for Division\n");
  scanf ("%d", &d);
  switch (d)
    {

    case 1:
      printf ("additiion is-%lf\n", a + b);
      break;
    case 2:
      printf ("Substraction is-%lf\n", a - b);
      break;
    case 3:
      printf ("Multiplication is-%lf\n", a * b);
      break;
    case 4:
      printf ("Division is-%lf\n", a / b);
      break;

    default:
      printf ("Enter corrrect option\n");

    }
  return 0;

}
