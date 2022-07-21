//Write a program to delete a node from linked list at starting position

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void display ();
void del_begin ();
void
main ()
{
  int b;
  a = NULL;
  t = (struct node *) malloc (sizeof (struct node));
  printf ("Enter no. of nodes:");
  scanf ("%d", &b);
  printf ("Node [1]:");
  scanf ("%d", &t->data);
  t->next = NULL;
  a = t;

  for (int i = 2; i <= b; i++)
    {
      t1 = (struct node *) malloc (sizeof (struct node));
      printf ("Node [%d]:", i);
      scanf (" %d", &t1->data);
      t->next = t1;
      t = t1;
    }
  t->next = NULL;
  printf ("Elements in linked list:\n");
  display ();
  del_begin ();
  printf ("Elements in linked list after deletion of first node\n");
  display ();
}

void
display ()
{
  t = a;
  while (t != NULL)
    {
      printf ("%d  ", t->data);
      t = t->next;
    }
  printf ("\n");

}

void
del_begin ()
{
  if (a == NULL)
    {
      printf ("underflow\n");
      return;
    }
  t = a;
  a = t->next;
  free (t);
}
