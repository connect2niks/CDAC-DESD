#include <stdio.h>
void
main ()
{
  float table[2][3] = { {1.1, 1.2, 1.3}, {2.1, 2.2, 2.3} };

  printf ("Value of table :%p\n", table);
  printf ("Value of (table+1) :%p\n", (table + 1));
  printf ("Value of *(table+1) :%p\n", *(table + 1));
  printf ("Value of (*(table+1)+1) :%p\n", (*(table + 1) + 1));
  printf ("Value of (*(table)+1) :%p\n", (*(table) + 1));
  printf ("Value of *(*(table+1)+1) :%.1f\n", *(*(table + 1) + 1));
  printf ("Value of *(*(table)+1) :%.1f\n", *(*(table) + 1));
  printf ("Value of *(*(table+1) :%.1f\n", *(*(table + 1)));
  printf ("Value of *(*(table)+1)+1 :%.1f\n", *(*(table) + 1) + 1);

}
