/*Write a program to read (from standard input) the Roll No, name and marks of a student and store it in a text file (Note: Provide text file name through command line).
If the file already exists, add information to it.
*/
#include<stdio.h>
int
main (int c, char *v[])
{

  FILE *s;
  char n[20];
  int rno;
  float m;
  s = fopen (v[1], "a+");

  if (s == NULL)
    {
      perror ("Error");
      return (-1);
    }

  for (int i = 1; i < 3; i++)
    {
      printf ("Student %d\nEnter name:", i);
      scanf ("%s", n);
      printf ("Enter roll no. :");
      scanf ("%d", &rno);
      printf ("Enter Marks :");
      scanf ("%f", &m);
      fprintf (s, "\nName:%s \nRoll no.:%d \nMarks:%.2f\n", n, rno, m);
    }

  fclose (s);
  return 0;
}
