//Write a program to implement stack using linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;
void create ();
void push ();
void display ();
void pop ();

void
main ()
{
  create ();
  printf ("Elements in stack using linked list:\n");
  display ();
  push ();
  printf ("Element in stack after push\n");
  display ();
  pop ();
  printf ("Elements in stack after pop an element:\n");
  display ();
}

void
create ()
{
  int b;

  t = (struct node *) malloc (sizeof (struct node));
  printf ("Enter no. of elements in stack:");
  scanf ("%d", &b);
  printf ("Element [1]:");
  scanf ("%d", &t->data);
  t->next = NULL;


  for (int i = 2; i <= b; i++)
    {
      t1 = (struct node *) malloc (sizeof (struct node));
      printf ("Element [%d]:", i);
      scanf (" %d", &t1->data);
      t1->next = t;
      t = t1;
    }
  a = t;
}

void
display ()
{
  t1 = a;
  while (t1 != NULL)
    {
      printf ("%d  ", t1->data);
      t1 = t1->next;
    }
  printf ("\n");

}

void
pop ()
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

void
push ()
{
  struct node *t3;
  t3 = (struct node *) malloc (sizeof (struct node));
  if (t3 == NULL)
    {
      printf ("overflow\n");
      return;
    }
  printf ("Input new node data:\n");
  scanf ("%d", &t3->data);
  t3->next = a;
  a = t3;
}
