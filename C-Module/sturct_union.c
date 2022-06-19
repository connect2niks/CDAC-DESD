//Structure and Union

#include <stdio.h>
#include <string.h>
struct detail1
{
  int a;
  char n[20];

} d1;

union detail2
{
  int b;
  char m[20];

} d2;

int
main ()
{
  printf ("size of the union :%ld\n", sizeof (d2));
  printf ("size of the structure :%ld\n", sizeof (d1));
  printf ("\nDetail using structure\n");
  d1.a = 29;
  strcpy (d1.n, "Nikhil");
  printf ("Age =%d\n", d1.a);
  printf ("Name =%s\n", d1.n);
  printf ("\nDetail using union\n");
  d2.b = 27;
  printf ("Age =%d\n", d2.b);
  strcpy (d2.m, "Akhil");
  printf ("Name =%s\n", d2.m);
  return 0;

}
