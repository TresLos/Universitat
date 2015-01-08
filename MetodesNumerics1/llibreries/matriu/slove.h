/*
   gauss
   triinf	Triangular inferior
   trisup	Triangular superior
*/

/**
  * Et soluciona la matriu triangular superior
  *
  * Ux = b, troba  la x
  * n, dimencio de la matriu
  * U, matriu triangular superior
  * b, vector amb les solucions que vols trobar
  * tol, tolerancia que tindra el programa
  *
  * @param b, retorna la solucio desitjada
  * 0, L'algoritme a sigut executat sense problemes
  */
int trisup (int n, double **U, double *b, double tol)
{
	int i, j;
/* Comprovacio previa abans de comensar */
	for (i = 0; i < n; i++)
		if (fabs (U[i][i]) < tol)
		{
			FM (U, n, n);
			FV (b, n);
			printf ("Hi ha zeros a la diagonal i se volia fer triangular superior");
			exit (1);
		}

/* Aqui fem el que realment desitjem */
	for (i = n -1; i >= 0; i--)
	{
		for (j = n -1; j > i; j--)
			b[i] -= U[i][j] * b[j];
		b[i] /= U[i][i];
	}

	return 0;
}

/**
  * Triangular superior en forma L
  *
  * L = Matriu inferior amb diagonal = Id.
  * aixi que no cal fer la divisio
  *
  * n, dimencio
  * L, matriu
  * b, vector
  *
  * b, es el vector amb el resultat desitjat
  */
void triinf (int n, double **L, double *b)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			b[i] -= L[i][j] * b[j];
}

/**
  * Fa gauss i soluciona els multiplicants a la mateixa matriu, on anirien els zeros
  *
  * n, dimencio de la matriu
  * A, matriu
  * b, vector a solucionar
  * tol, tolerancia
  *
  * Return
  * 0, tot correcte
  * -1, la diagonal ha quedat nula, no se pot solucionar per gauss
  *
  * Vercio corregida (que la entrada era erronia)
  * ara tot funciona com hauria :)
  */
int gauss (int n, double **A, double *b, double tol)
{
	int k, i, j;
	double m;

	for (k = 0; k < n -1; k++)
	{
		if (fabs (A[k][k]) < tol)
		{
			FM (A, n, n);
			FV (b, n);
			printf ("Parem, perque aixo fa la matriu sense pivotatge i es menor que la tolerancia");
			exit (1);
		}
		for (i = k +1; i < n; i++)
		{
			m = A[i][k] / A[k][k];
			b[i] -= m * b[k];
			A[i][k] = m;
			for (j = k +1; j < n; j++)
				A[i][j] -= m * A[k][j];
		}
	}

	return 0;
}
