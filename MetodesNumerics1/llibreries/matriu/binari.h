/*
   PMM	Producte entre matrius
   PMV	Producte matriu amb vector
*/

/**
  * Producte de matriu amb vector Ax = b
  *
  * A, matriu m, n
  * x, vector n, 1
  * m, n, dimencions
  *
  * @return b, solucio m x 1
  * aparentment funciona correctament
  */
double *PMV (double **A, double *x, int m, int n)
{
	double *b = GVZ (n);

	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			b[i] += A[i][j] * x[j];
	return b;
}

/**
  * Producte entre dues matrius
  * http://en.wikipedia.org/wiki/Matrix_multiplication
  *
  * A, matriu m, n
  * B, matriu n, p
  * m, n, p dimencions
  *
  * @return C, solucio m x n
  * no esta assegurat el seu bon funcionament
  */
double **PMM (double **A, double **B, int m, int n, int p)
{
	double **C = GMZ (m, p);

	int i, j, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++)
			for (k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}
