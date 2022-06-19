/*Write a program to read the Roll No, name and marks of a student and store it in to a binary file and read student records and print on standard output (use fwrite and fread library functions.*/

#include <stdio.h>
struct stud
{
  char n[20];
  int r;
  float m;
};
int
main ()
{
  struct stud a, b;
  FILE *f;
  int i;
  f = fopen ("file.bin", "wb");

  printf ("Enter name :");
  scanf ("%s", a.n);
  printf ("Enter roll no. :");
  scanf ("%d", &a.r);
  printf ("Enter marks :");
  scanf ("%f", &a.m);

  fwrite (&a, sizeof (a), 1, f);


  fclose (f);

  f = fopen ("file.bin", "rb");
  while (1)
    {
      if (fread (&b, sizeof (b), 1, f) == 1)
	printf ("Name :%s, Roll no. :%d, Marks :%.2f\n", b.n, b.r, b.m);
      else
	break;
    }
  fclose (f);

  return 0;

}
