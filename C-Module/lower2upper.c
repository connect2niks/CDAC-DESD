//Write a program to convert lower case string to upper case string and vice versa

#include <stdio.h>
#include <string.h>

int
main ()
{
  char s[100];
  int i;
  printf ("\nEnter a string : ");
  gets (s);

  for (i = 0; s[i] != '\0'; i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
	{
	  s[i] = s[i] - 32;
	}
      else if (s[i] >= 'A' && s[i] <= 'Z')
	{
	  s[i] = s[i] + 32;
	}

    }
  printf ("\nOutput = %s", s);
  return 0;
}
