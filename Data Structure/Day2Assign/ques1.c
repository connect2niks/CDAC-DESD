//Implement Stack using Array

#include <stdio.h>
#define MAX 10
int a[MAX];
int t = -1;

void
push (int x)
{
  if (t == MAX - 1)
    {
      printf ("Stack overflow\n");
      return;
    }
  t = t + 1;
  a[t] = x;
}

void
pop ()
{
  if (t == -1)
    {
      printf ("Empty stack\n");
      return;
    }
  t--;
}

int
top ()
{
  return a[t];
}

int
isempty ()
{
  if (t == -1);
  return 1;
  return 0;

}

void
print ()
{
  int i;
  printf ("Stack:");
  for (i = 0; i <= t; i++)
    {
      printf ("..%d..", a[i]);
    }
  printf ("\n\n");
}

int
main ()
{
  printf ("push 5\n");
  push (5);
  print ();
  printf ("push 8\n");

  push (8);
  print ();
  printf ("push 9\n");

  push (9);
  print ();
  printf ("pop\n");

  pop ();
  print ();
  printf ("push 10\n");

  push (10);
  print ();
  return 0;
}
