    /*Write a C program to perform the following operations on two strings using intrinsic functions.
       • Concatenate two strings
       • Find the length of each string
       • Compare two strings
       • Copy string
       • Find whether string1 is the subset of the second string or not(strstr) */


#include<stdio.h>
#include<string.h>

int
main ()
{
  char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], *r;

  printf ("Enter first string:\n");
  scanf ("%s", s1);

  printf ("Enter second string: \n");
  scanf ("%s", s2);

  printf ("Length of first string is: %ld\n", strlen (s1));
  printf ("Length of second string is: %ld\n", strlen (s2));

  if (strcmp (s1, s2) == 0)
    printf ("First and second strings are same\n");
  else
    printf ("strings are not same\n");

  printf ("Enter a string:");
  scanf ("%s", s3);
  strcpy (s4, s3);
  puts (s4);

  printf ("Enter main string:\n");
  scanf ("%s", s5);

  printf ("Enter sub string: \n");
  scanf ("%s", s6);

  r = strstr (s5, s6);
  if (r != NULL)
    printf ("string 1 is the subset of string 2\n");
  else
    printf ("string 1 is not the subset of string 2\n");


  strcat (s1, s2);
  printf ("After concatenation: %s", s1);
  printf ("\n");

  return (0);

}
