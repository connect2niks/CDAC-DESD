#include <stdio.h>
typedef struct complex
{
  float r1, r2;
  float i1, i2;
} complex;

complex add (complex n1, complex n2);
complex sub (complex m1, complex m2);
int
main ()
{

  complex n1, n2, result1, m1, m2, result2;

  printf ("Enter the complex number for addition\n");
  printf ("For 1st complex number enter the real and imaginary parts: ");
  scanf ("%f %f", &n1.r1, &n1.i1);

  printf ("For 2nd complex number enter the real and imaginary parts: ");
  scanf ("%f %f", &n2.r1, &n2.i1);

  result1 = add (n1, n2);

  printf ("Sum = %.1f + %.1fi\n\n", result1.r1, result1.i1);


  printf ("Enter the complx number for substraction\n");

  printf ("For 1st complex number enter the real and imaginary parts: ");
  scanf ("%f %f", &m1.r2, &m1.i2);

  printf ("For 2nd complex number enter the real and imaginary parts: ");
  scanf ("%f %f", &m2.r2, &m2.i2);

  result2 = sub (m1, m2);

  printf ("Difference = %.1f - %.1fi\n\n", result2.r2, result2.i2);
  return 0;
}

complex
add (complex n1, complex n2)
{
  complex temp;
  temp.r1 = n1.r1 + n2.r1;
  temp.i1 = n1.i1 + n2.i1;
  return (temp);
}

complex
sub (complex m1, complex m2)
{
  complex temp;
  temp.r2 = m1.r2 - m2.r2;
  temp.i2 = m1.i2 - m2.i2;
  return (temp);

}
