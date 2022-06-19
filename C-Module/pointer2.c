#include <stdio.h>
void
main ()
{
  char *color[6] = { "red", "green", "blue", "white", "black", "yellow" };

  printf ("value of color :%p\n", color);

  printf ("value of (color+2) :%p\n", (color + 2));

  printf ("value of *color :%s\n", *color);

  printf ("value of *(color+2) :%s\n", *(color + 2));

  printf ("value of color[5] :%p\n", color[5]);

  printf ("value of *(color + 5) :%s\n", *(color + 5));

}
