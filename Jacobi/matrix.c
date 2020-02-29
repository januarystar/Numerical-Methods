#include "stdlib.h"
#include "matrix.h"

#include <math.h>


double* MatrMulVec(double** A, double* b, int M, int N)
{
  int i, j;
  double* x = malloc(sizeof(double) * N);

  for (i = 0; i < M; i++)
  {
    double r = 0;
    for (j = 0; j < N; j++)
      r += A[i][j] * b[j];
    x[i] = r;
  }

  return x;
}


double* VecMulMatr(double* b, double** A, int M, int N)
{
  int i, j;
  double* x = malloc(sizeof(double) * N);

  for (i = 0; i < M; i++)
  {
    double r = 0;
    for (j = 0; j < N; j++)
      r += b[i] * A[j][i];
    x[i] = r;
  }

  return x;
}


double** MatrMulMatr(double** A, double** B, int M, int N, int K)
{
  double** C = malloc(sizeof(double*) * M);
  int i, j, k;

  for (i = 0; i < M; i++)
    C[i] = malloc(sizeof(double) * K);

  for (i = 0; i < M; i++)
    for (j = 0; j < K; j++)
    {
      C[i][j] = 0;
      for (k = 0; k < N; k++)
        C[i][j] += A[i][k] * B[k][j];
    }

  return C;
}


double** Transposing(double** A, int M, int N)
{
  double** At = malloc(sizeof(double*) * N);
  int i, j;

  for (i = 0; i < N; i++)
    At[i] = malloc(sizeof(double) * M);

  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      At[i][j] = A[j][i];

  return At;
}


double* VecMulNum(double* x, int N, double Num)
{
  double* v = malloc(sizeof(double) * N);
  int i;

  for (i = 0; i < N; i++)
    v[i] = x[i] * Num;

  return v;
}


double DotProduct(double* X, double* Y, int N)
{
  int i;
  double dp = 0;

  for (i = 0; i < N; i++)
    dp += X[i] * Y[i];

  return dp;
}


int IsEqual(double* X, double* Y, int N)
{
  int i;
  double eps = 1e-16;
  double* a = malloc(N * sizeof(double));

  for (i = 0; i < N; i++)
    a[i] = X[i] - Y[i];

  if (DotProduct(a, a, N) < eps)
    return 0;
  return (int)(log(DotProduct(a, a, N)) / log(10.0) + 0.5);
}

double SqrNorm(double* x, double M)
{
  double Norm1 = 0;
  double Norm = 0;
  int i = 0;

  for (i = 0; i < M; i++)
    Norm1 += pow(x[i], 2);

  Norm = sqrt(Norm1);

  return Norm;
}