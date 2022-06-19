// C program to remove all characters in a string except alphabets

#include<stdio.h>
int
main ()
{
  char s[100];
  int i, j;
  printf ("\nEnter a string : ");
  gets (s);
  for (i = 0; s[i] != '\0'; ++i)
    {
      while (!
	     ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
	      || s[i] == '\0'))
	{
	  for (j = i; s[j] != '\0'; ++j)
	    {
	      s[j] = s[j + 1];
	    }
	  s[j] = '\0';
	}
    }
  printf ("\nOutput after remove all character except alphabets : ");
  puts (s);
  return 0;
}
