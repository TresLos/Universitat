#include "magia.h"

int
main ()
{
	int n;
	double *x, *f;
	printf ("\nEntreu les coordenades\n");
	n = HGVM (&x);
	printf ("\nEntreu els valors\n");
	f = GVM (n);

/* Obte el polinomi desitjat */
	difdiv (n, x, f);

/* Dibuixa el polinomi */
	writeFile (n, 1e-5, -3, 5, x, f);

	return 0;
}
