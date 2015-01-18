#include "magia.h"

int
main ()
{
	int n;
	double *x, *f;
	printf ("\nEntreu les coordenades\n");
	x = HGVM (&n);
	printf ("\nEntreu els valors\n");
	f = GVM (n);

/* Obte el polinomi desitjat */
	difdiv (n, x, f);

/* Dibuixa el polinomi */
	writeFile (n, 1e-2, -1, 1, x, f);

	FV (f, n);
	FV (x, n);
	return 0;
}
