
double NSum(double **A, int N)
{
  int i = 0, j = 0;
  double S = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (i != j)
        S += A[i][j] * A[i][j];

  return S;
}