//Write a program to Sort a stack using a temporary stack

#include <stdio.h>
#define MAX 10

int a[MAX], b[MAX];
int t1 = -1;
int t2 = -1;
void push (int x);
void tpush (int y);
void display ();
void tdisplay ();
void sort ();
int pop ();
int tpop ();

// Main function

int
main ()
{
  int x, i;
  printf ("Enter 10 elements of input stack :\n\n");
  for (i = 0; i < MAX; i++)
    {
      scanf ("%d", &x);
      push (x);
    }
  printf ("\nInput stack:\n");
  display ();
  sort ();
  printf ("\nstack after sorting\n");
  tdisplay ();

  return 0;
}

//input stack  push function

void
push (int x)
{
  if (t1 == MAX - 1)
    {
      printf ("overflow");
      return;
    }
  t1 = t1 + 1;
  a[t1] = x;
}

//input stack display function

void
display ()
{
  int i;
  for (i = 0; i <= t1; i++)
    {
      printf ("%d  ", a[i]);
    }
  printf ("\n");
}

//output stack display function

void
tdisplay ()
{
  int i;
  for (i = 0; i <= t2; i++)
    {
      printf ("%d  ", b[i]);
    }
  printf ("\n");
}

// sort function

void
sort ()
{
  int c;
  while (t1 != -1)
    {
     c = a[t1];
     pop ();
      while (t2 != -1 && b[t2] > c)
	{
	  push (b[t2]);
	  tpop ();
	}
      tpush (c);
    }
}

//temperary stack  push function

void
tpush (int y)
{
  if (t2 == MAX - 1)
    {
      printf ("overflow");
      return;
    }
  t2 = t2 + 1;
  b[t2] = y;
}

// input stack pop function

int
pop ()
{
  if (t1 == -1)
    {
      return (-1);
    }
  t1 = t1 - 1;
}

// temperary stack pop function

int
tpop ()
{
  if (t2 == -1)
    {
      return (-1);
    }
  t2 = t2 - 1;
}
