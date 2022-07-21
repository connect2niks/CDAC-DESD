//Write a menu driven program for stack implementation

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int s[MAX];
int t = -1;
void push ();
void pop ();
void display ();

int
main ()
{
  int ch = 1;

  while (ch)
    {
      printf ("**********STACK OPERATIONS**********");
      printf ("\n1.push");
      printf ("\n2.pop");
      printf ("\n3.exit");
      printf ("\nEnter your choice :");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  push ();
	  break;
	case 2:
	  pop ();
	  break;
	case 3:
	  exit (0);
	default:
	  printf ("Enter correct choice");
	}
    }

}

void
display ()
{
  int i;
  printf ("Stack :");
  for (i = 0; i <= t; i++)
    {
      printf ("%d ", s[i]);
    }
  printf ("\n");
}

void
push ()
{
  int a;
  if (t == MAX - 1)
    {
      printf ("over flow");
      return;
    }
  t++;
  printf ("\nEnter number:");
  scanf ("%d", &a);
  s[t] = a;
  printf ("Elements in stack are :\n");
  display ();
}

void
pop ()
{
  if (t == -1)
    {
      printf ("Stack underflow");
      return;

    }
  else
    {
      t = t - 1;
      printf ("Elements in stack are :\n");
      display ();
    }
}
