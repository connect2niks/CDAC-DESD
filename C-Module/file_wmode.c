#include <stdio.h>
int
main ()
{
  FILE *f;
  f = fopen ("file.txt", "w");
  fputs ("Nikhil yadav\n", f);
  fputs ("B.tech in electronics and communication engineering\n", f);
  fputs ("CDAC ACTS\n", f);
  fputs ("DESD Bangalore\n", f);

  printf ("1. Type \"wc -m file.txt\" for  character in file.txt\n");
  printf ("2. Type \"wc -l file.txt\" for  lines in file.txt\n");
  printf ("3. Type \"wc -w file.txt\" for  words in file.txt\n");

  fclose (f);
  return 0;

}
