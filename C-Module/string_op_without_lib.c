/*    Write a C program to perform the following operations on two strings without using string library functions.
      ▪ Concatenate two strings
      ▪ Find the length of each string
      ▪ Compare two strings
      ▪ Copy string
      ▪ Reverse the string */

#include<stdio.h>
void
main ()
{

  char s1[50], s2[50], s3[50], s4[50], s5[50], s6[50], t;
  int i, j, l = 0, m = 0, a = 0, b = 0;
  //for concatenation
  printf ("Enter first string:");
  scanf ("%s", s1);

  printf ("Enter second string:");
  scanf ("%s", s2);

  for (i = 0; s1[i] != '\0'; i++);

  for (j = 0; s2[j] != '\0'; j++, i++)
    {

      s1[i] = s2[j];

    }

  s1[i] = '\0';
  printf ("After concatenation:%s", s1);
  printf ("\n");
//for length of string
  for (int k = 0; s1[k] != '\0'; k++)

    l++;
  printf ("Length of the string %s is %d\n", s1, l);
  //for compare string
  printf ("Enter two string to compare :");
  scanf ("%s", s3);
  scanf ("%s", s4);

  while (s3[m] == s4[m] && s3[m] != '\0')
    m++;
  if (s3[m] > s4[m])
    printf ("string 1 > string 2");
  else if (s3[m] < s4[m])
    printf ("string 1 < string 2");
  else
    printf ("string 1 = string 2");

//for copying string
  printf ("\nEnter the string for copying:");
  scanf ("%s", s5);

  int n = 0;
  while (s5[n] != '\0')
    {
      s6[n] = s5[n];
      n++;
    }

  s6[i] = '\0';
  printf ("Copied String is %s ", s6);
//for reverse the string
  b = l - 1;
  while (a < b)
    {

      t = s1[a];
      s1[a] = s1[b];
      s1[b] = t;
      a++;
      b--;

    }
  printf ("\nReverse string after concatenate :%s\n", s1);


}
