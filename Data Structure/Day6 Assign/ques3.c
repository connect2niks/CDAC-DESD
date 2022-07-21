//Write a program to delete a node from linked list at nth position

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void display ();
void del_nth ();
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
  del_nth ();
  printf ("Elements in linked list after deletion of nth node\n");
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
del_nth ()
{
  int n;
  if (a == NULL)
    {
      printf ("underflow\n");
      return;
    }
  t1 = a;
  printf ("Enter node which you want to delete:\n");
  scanf ("%d", &n);
  for (int i = 1; i < n; i++)
    {
      t = t1;
      t1 = t1->next;
    }
  t->next = t1->next;
  free (t1);
}
