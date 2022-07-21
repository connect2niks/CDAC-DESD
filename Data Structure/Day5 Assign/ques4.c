//Write a program to insert a new node after nth node

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void display ();
void insert_nth ();
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
  insert_nth ();
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
insert_nth ()
{
  int n;
  t = (struct node *) malloc (sizeof (struct node));
  printf ("\nEnter the data for the new  node:\n");
  scanf ("%d", &t->data);
  printf ("Enter the position after which you want to insert the new node\n");
  scanf ("%d", &n);
  t1 = a;
  for (int i = 1; i < n; i++)
    {
      t1 = t1->next;
    }

  t->next = t1->next;
  t1->next = t;

}
