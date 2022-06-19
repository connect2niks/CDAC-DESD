//Implement string library functions strlen, strcpy, strcat, strcmp with same return values and all error handling features using pointers

#include<stdio.h>
#include<string.h>

int
main ()
{

  char r[50], a[50], b[50], s[50];
  printf ("Enter the string \n");
  gets (s);
  printf ("length of entered string is %ld\n", strlen (s));
  strcpy (r, s);
  puts (r);
  strcat (s, r);
  puts (s);
  printf ("Enter two  string for compare :");
  scanf ("%s", &a);
  scanf ("%s", &b);
  if (strcmp (a, b) == 0)

    printf ("string matched");
  else
    printf ("strings are not matched");

  return 0;
}
