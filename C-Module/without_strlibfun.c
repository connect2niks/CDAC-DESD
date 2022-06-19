
#include<stdio.h>

char
cat (char *s1, char *s2)
{
  while (*s1 != '\0')
    s1++;
  while (*s2 != '\0')
    {
      *s1 = *s2;
      s1++;
      s2++;

    }
  *s1 = '\0';

}

int
len (char *s3)
{

  int l = 0;
  while (*s3 != '\0')
    {
      l++;
      s3++;

    }

  return l;
}


void
cpy (char *s4, char *s5)
{

  while (*s4 != '\0')
    {
      *s5 = *s4;
      s5++;
      s4++;

    }



}

int
comp (char *s6, char *s7)
{
  int s = 0;
  while ((*s6 != '\0') || (*s7 != '\0'))
    {
      s = s + (*s6 - *s7);
      s6++;
      s7++;

    }
  return s;

}



int
main ()
{
  char s3[50];
  int l;
  printf ("\nEnter string");
  scanf ("%s", s3);
  l = len (s3);
  printf ("length of string %s is %d", s3, l);


  char s1[25], s2[25];
  printf ("Enter first string to concatenate :");
  gets (s1);

  printf ("Enter second string to concatenate :");
  gets (s2);

  s1 = (s1, cat(s1, s2));
  printf ("concatenated string :%s\n", s1);


  char s4[50], s5[50];
  printf ("Enter string :");
  gets (s4);
  cpy (s4, s5);
  printf ("string copied :%s\n", s5);

  char s6[50], s7[50];
  int r;
  printf ("Enter first string :");
  gets (s6);
  printf ("Enter second string :");
  gets (s7);

  r = comp (s6, s7);
  printf ("string after compared", r);

  return 0;
}
