//Write a program in C to count the number of vowels and consonants in a string using a pointer

#include <stdio.h>
#include <string.h>
void
main ()
{
  char a[100];
  char *p;
  int i = 0, j = 0;

  printf ("\nEnter a string\n");
  gets (a);
  p = a;
  while (*p != '\0')
    {
      if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u'
	  || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
	i++;
      else
	j++;



      p++;

    }

  printf ("Number of vovels in string :%d\n", i);
  printf ("Number of consonants in string :%d\n", j);


}
