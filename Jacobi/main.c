#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "jacobi.h"

int LoadFromFile(FILE* F, double*** A, int* N)
{
  int i, j;

  if (fscanf(F, "%i", N) < 1)
    return 0;

  *A = malloc(*N * sizeof(double*));

  for (i = 0; i < *N; i++)
    (*A)[i] = malloc(sizeof(double) * *N);

  for (i = 0; i < *N; i++)
    for (j = 0; j < *N; j++)
      fscanf(F, "%lf", &((*A)[i][j]));

  return 1;
}


int main(void)
{
  double** A = NULL;
  int N;
  double eps = 1e-4;

  int i = 0, j = 0;

  FILE* Fin = fopen("m.in", "r");
  FILE* Fout = fopen("eig.out", "w");

  if (Fin == NULL || Fout == NULL)
    return 0;

  while (LoadFromFile(Fin, &A, &N))
  {
    JacobiFind(A, N, eps);
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
        fprintf(Fout, "%.5lf", A[i][j]);
      fprintf(Fout, "\n");
    }
  }
}