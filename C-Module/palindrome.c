//Write a program to find whether given number is palindrome or not

#include<stdio.h>
int
main ()
{
  int t, r, s = 0, n;
  printf ("Enter a number:");
  scanf ("%d", &n);
  t = n;
  while (n > 0)
    {
      r = n % 10;
      s = (s * 10) + r;
      n = n / 10;

    }
  if (s == t)

    printf ("palindrome no.\n");

  else
    printf ("not palindrome\n");

  return 0;
}
