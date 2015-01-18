#include "matriu.h"

int main (void)
{
	int n;
	double tol = 1e-8;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	double **A = GMM (n, n);
	printf ("\nEntri la vector:\n");
	double *b = GVM (n);
	SM (A, n, n);
	SV (b, n);
	printf ("\nEl que has entrat mostrat:");
/* Copy past d'entrada manual */

	gauss (n, A, b, tol);
		printf ("Primera resolucio:\n");
		SM (A, n, n);
		SV (b, n);


			trisup (n, A, b, tol);
			printf ("Solucio final.\n");
			SV (b, n);
/* Alliberant memoria */
	FV (b, n);
	FM (A, n, n);
	return 0;
}
