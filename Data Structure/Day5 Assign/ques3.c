//Write a program to insert a new node at the end to the linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void display ();
void insert_end ();
void
main ()
{
  int b;
  a = NULL;
  t = (struct node *) malloc (sizeof (struct node));
  printf ("enter no. of nodes:");
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
  insert_end ();
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
insert_end ()
{
  t = (struct node *) malloc (sizeof (struct node));
  printf ("input new node data:");
  scanf ("%d", &t->data);
  t1 = a;
  while (t1->next != NULL)
    t1 = t1->next;
  t1->next = t;
  t->next = NULL;
}
