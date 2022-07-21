#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *a, *t, *t1;

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
}
