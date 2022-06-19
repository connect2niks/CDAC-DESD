//Write a C Program to Count the Number of Vowels, Consonants, digits and remaining characters in given string

#include<stdio.h>
int
main ()
{

  char s[100];

  int i, v = 0, c = 0, d = 0, sp = 0, sy = 0;

  printf ("Enter a string :");
  gets (s);
  for (i = 0; s[i] != '\0'; ++i)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
	  s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
	  s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
	{
	  v++;
	}
      else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
	{
	  c++;
	}
      else if (s[i] >= '0' && s[i] <= '9')
	{
	  d++;
	}
      else if (s[i] == ' ')
	{
	  sp++;
	}
      else
	{
	  sy++;
	}
    }
  printf ("Vowels: %d", v);
  printf ("\nConsonants: %d", c);
  printf ("\nDigits: %d", d);
  printf ("\nWhite spaces: %d", sp);
  printf ("\nSymbols: %d\n", sy);
  return 0;
}
