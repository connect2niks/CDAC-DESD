// Tranpose of a matrix.

#include <stdio.h>
int
main ()
{
  int a[10][10], b[10][10], n, m, i, j;
  printf ("Enter rows and columns: ");
  scanf ("%d %d", &n, &m);

  printf ("\nEnter matrix elements:\n");
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      {
	printf ("Enter element a%d%d: ", i + 1, j + 1);
	scanf ("%d", &a[i][j]);
      }

  printf ("\nEntered matrix: \n");
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      {
	printf ("%d  ", a[i][j]);

	if (j == m - 1)
	  printf ("\n");
      }

  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      {
	b[j][i] = a[i][j];
      }

  printf ("\nTranspose of the matrix:\n");
  for (i = 0; i < m; ++i)
    for (j = 0; j < n; ++j)
      {
	printf ("%d  ", b[i][j]);
	if (j == n - 1)
	  printf ("\n");
      }
  return 0;
}
