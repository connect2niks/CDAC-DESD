//sorting of string

#include<stdio.h>
#include<string.h>
int
main ()
{
  int i, j, n;

  char s[10][10], t[10];
  printf ("Number of string: ");
  scanf ("%d", &n);

  printf ("Enter %d Strings: ", n);
  for (i = 0; i <= n; i++)
    gets (s[i]);

  for (i = 0; i <= n; i++)

    for (j = i + 1; j <= n; j++)
      {
	if (strcmp (s[i], s[j]) > 0)
	  {
	    strcpy (t, s[i]);
	    strcpy (s[i], s[j]);
	    strcpy (s[j], t);
	  }
      }
  printf ("Alphabetically sorted string:");
  for (i = 0; i <= n; i++)
    puts (s[i]);

  return 0;
}
