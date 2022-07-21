//Write a program to delete a node from linked list at last position

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void display ();
void del_last ();
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
  del_last ();
  printf ("Elements in linked list after deletion of last node\n");
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
del_last ()
{
  if (a == NULL)
    {
      printf ("underflow\n");
      return;
    }
  t = a;
  while (t->next != NULL)
    {
      t1 = t;
      t = t->next;
    }
  t1->next = NULL;
  free (t);
}
