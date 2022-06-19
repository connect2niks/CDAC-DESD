/*Write a program that will concatenate two files, that is append the contents of one file at the end of another file and write the results into a third file.*/

#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  FILE *f1;
  FILE *f2;
  FILE *f3;
  char c;
  f1 = fopen ("file1.txt", "w+");
  f2 = fopen ("file2.txt", "w+");
  f3 = fopen ("file3.txt", "a+");
  fputs ("This is file 1\t", f1);
  fputs ("This  is file 2\n", f2);
  rewind (f1);
  rewind (f2);
  while ((c = fgetc (f1)) != EOF)
    fputc (c, f3);

  while ((c = fgetc (f2)) != EOF)
    fputc (c, f3);

  printf
    ("cat file3.txt for viewing concatenated strings of file 1 and file 2\n");
  fclose (f1);
  fclose (f2);
  fclose (f3);
  return 0;
}
