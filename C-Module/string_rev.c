//To find reverse of a string.

#include<stdio.h>
#include<string.h>
void
main ()
{
  char s1[100], s2[100];
  char *p1, *p2;
  printf ("Enter a String:\n");
  gets (s1);
  p1 = s1 + strlen (s1)-1;
  p2 = s2;
  while (p1 >= s1)
    {
      *p2 = *p1;
      p2++;
      p1--;
    }
  *p2 = '\0';
  printf ("String before reverse: %s\n", s1);
  printf ("String after reverse: %s\n", s2);

}
