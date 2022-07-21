//Write a program to implement queue using linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int d;
  struct node *n;
};

struct node *f = NULL;
struct node *r = NULL;
void create ();
void display ();
void dequeue ();
void enqueue ();
void
main ()
{
  create ();
  printf ("Elements in queue are:\n");
  display ();
  dequeue ();
  printf ("Elements in queue after dequeue an elements:\n");
  display ();
  enqueue ();
  printf ("Elements in queue after enqueue an element:\n");
  display ();
}

void
create ()
{
  int x, y;
  printf ("Enter the no. of elements in queue:");
  scanf ("%d", &y);
  for (int i = 1; i <= y; i++)
    {
      printf ("Element[%d]:", i);
      scanf ("%d", &x);
      struct node *t = (struct node *) malloc (sizeof (struct node));
      t->d = x;
      t->n = NULL;
      if (f == NULL && r == NULL)
	{
	  f = r = t;
	}
      else
	{
	  r->n = t;
	  r = t;
	}
    }
}


void
display ()
{
  struct node *t = f;
  while (t != NULL)
    {
      printf ("%d  ", t->d);
      t = t->n;
    }
  printf ("\n");
}

void
dequeue ()
{
  struct node *t = f;
  if (f == NULL)
    {
      printf ("Queue is empty");
      return;
    }
  if (f == r)
    {
      f = r = NULL;
    }
  else
    {
      f = f->n;
    }
  free (t);
}

void
enqueue ()
{
  int x;
  printf ("Element for Enqueue: ");
  scanf ("%d", &x);
  struct node *t = (struct node *) malloc (sizeof (struct node));
  t->d = x;
  t->n = NULL;
  if (f == NULL && r == NULL)
    {
      f = r = t;
    }
  else
    {
      r->n = t;
      r = t;
    }
}
