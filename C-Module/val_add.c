//Program should print the address of, and value stored in, each of the variables. 

#include <stdio.h>
void
main ()
{
  int i;
  float k;
  double m;
  char a;
  i = 10;
  k = 12.35;
  m = 25.324;
  a = 'A';

  printf ("value of integer i:%d\n ", i);

  printf ("address of i:%p\n", &i);


  printf ("value of float k :%f\n ", k);

  printf ("address of k :%p\n", &k);

  printf ("value of double m:%f\n ", m);

  printf ("address of m :%p\n", &m);


  printf ("value of char a:%c\n ", a);

  printf ("address of a :%p\n", &a);


}
