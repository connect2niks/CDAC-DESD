//Write a program to implement circular Queue using Array

#include <stdio.h>
#define N 10
int q[N];

int f = -1, r = -1;
void enqueue ();
void create ();
void dequeue ();
void display ();

void
main ()
{
  create ();
  display ();
  enqueue ();
  printf ("\nQueue after insert an element\n");
  display ();
  dequeue ();
  printf ("\n\nAfter dequeue\n");
  display ();

}

void
create ()
{
  int a, b;
  printf ("\nEnter no. of elements in queue\n");
  scanf ("%d", &a);
  printf ("\nEnter elements:\n");
  for (int i = 0; i < a; i++)
    {
      if (r == (N - 1))
	return;
      else if (f == -1 && r == -1)
	f = r = 0;
      else
	{
	  r = r + 1;
	}
      scanf ("%d", &b);
      q[r] = b;
    }
}

void
display ()
{
  int i;
  printf ("\nElements in queue are :\n");
  for (i = f; i <= r; i++)
    printf ("%d  ", q[i]);
  printf ("\n");
}

void
enqueue ()
{
  int m;
  if ((r + 1) % N == f)
    {
      printf ("\nQueue is overflow\n");
      return;
    }
  else if (f == -1 && r == -1)
    {
      f = r = 0;
    }
  else
    {
      r = (r + 1) % N;
    }
  printf ("\nInpur new element to insert\n");
  scanf ("%d", &m);
  q[r] = m;
}

void
dequeue ()
{
  if (f == -1 && r == -1)
    {
      printf ("\nQueue is empty\n");
      return;
    }
  else if (f == r)
    {
      f = r = -1;
    }
  else
    f = (f + 1) % N;
}
