#include "def.h"

double* MatrMulVec(double** A, double* b, int M, int N);
double* VecMulMatr(double* b, double** A, int M, int N);
double** MatrMulMatr(double** A, double** B, int M, int N, int K);
double** Transposing(double** A, int M, int N);
double* VecMulNum(double* x, int N, double Num);
double DotProduct(double* X, double* Y, int N);
int IsEqual(double* X, double* Y, int N);
double SqrNorm(double* x, double M);