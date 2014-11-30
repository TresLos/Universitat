#include "../magia.h"

int main (void)
{
	double *x, *f, *c;
	int n;
	printf ("\nEntra la n:\n");
		scanf ("%d", &n);
	printf ("\nEntreu les x's:\n");
	x = GVM (n);
	printf ("\nEntreu les f's:\n");
	f = GVM (n);
/* Entrada necessaria */

	SV (n, f);
	SV (n, x);
	difdivC (n, x, f, &c);
	SV (n, c);
	return 0;
}
