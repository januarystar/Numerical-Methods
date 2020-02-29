#include <math.h>
#include <stdlib.h>

int sign(double x)
{
  if (x > 0)
    return 1;
  if (x < 0)
    return -1;
  return 0;
}

int* SearchMax(double** A, int N)
{
  int k = 0, m = 0;
  double res = 0;
  int* i0j0 = NULL;
  i0j0 = malloc(2 * sizeof(int));
  if (i0j0 == NULL)
    exit(-1);
  res = A[1][1];
  for (k = 1; k < N; k++)
    for (m = k + 1; m < N; m++)
      if (fabs(A[k][m] >= fabs(res)))
        res = A[k][m];
  i0j0[0] = k;
  i0j0[1] = m;

  return i0j0;
}


void JacobiStep(double** A, int N, int i0, int j0)
{
  double cos = 0, sin = 0;
  double x, y;
  int m = 0;

  if (A[i0][i0] == A[j0][j0])
    cos = sin = sqrt(2) / 2;
  else
  {
    x = -2 * A[i0][j0];
    y = A[i0][i0] - A[j0][j0];
    cos = sqrt(0.5 * (1 + (fabs(y) / sqrt(x * x + y * y))));
    sin = (sign(x * y) * fabs(x)) / (2 * cos * sqrt(x * x + y * y));
  }

  for (m = 0; m < N; m++)
  {
    if (m != i0 && m != j0)
    {
      double ai0m, aj0m;
      if (m > i0)
        ai0m = A[i0][m];
      else
        ai0m = A[m][i0];
      if (m > j0)
        aj0m = A[j0][m];
      else
        aj0m = A[m][j0];

      if (m > i0)
        A[i0][m] = cos * ai0m - sin * aj0m;
      else
        A[m][i0] = cos * ai0m - sin * aj0m;
      if (m > j0)
        A[j0][m] = sin * ai0m + cos * aj0m;
      else
        A[m][j0] = sin * ai0m + cos * aj0m;
    }
  }

  A[i0][i0] = cos * cos * A[i0][i0] - 2 * sin * cos * A[i0][j0] + sin * sin * A[j0][j0];
  A[j0][j0] = sin * sin * A[i0][i0] + 2 * sin * cos * A[i0][j0] + cos * cos * A[j0][j0];
  A[i0][j0] = (cos * cos - sin * sin) * A[i0][j0] + cos * sin * (A[i0][i0] - A[j0][j0]);
}

void JacobiFind(double** A, int N, double eps)
{
  int* i0j0 = NULL;
  i0j0 = SearchMax(A, N);
  while (fabs(A[i0j0[0]][i0j0[1]]) > eps)
  {
    i0j0 = SearchMax(A, N);
    JacobiStep(A, N, i0j0[0], i0j0[1]);
  }
}