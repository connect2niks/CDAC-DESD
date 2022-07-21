//Write a program to Sort an array using a stacks

#include <stdio.h>
#define MAX 10

int a[MAX], b[MAX];
int arr[MAX];
int t1 = -1;
int t2 = -1;
void push (int x);
void tpush (int y);
void arrdisplay ();
void sort ();
int pop ();
int tpop ();

// Main function

int
main ()
{
  int x, i, e;
  printf ("Enter the 10 Elements of array\n\n");
  for (i = 0; i < MAX; i++)
    {
      scanf ("%d", &arr[i]);
    }
  printf ("Array before sorting\n");
  for (i = 0; i < MAX; i++)
    {
      printf ("%d  ", arr[i]);
    }

  for (i = 0; i < MAX; i++)
    {
      push (arr[i]);
    }
  sort ();
  printf ("\nArray after sorting\n");
  arrdisplay ();

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

//Array after sorting display function

void
arrdisplay ()
{
  int i;
  for (i = 0; i <= t2; i++)
    {
      arr[i] = b[i];
      printf ("%d  ", arr[i]);
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
