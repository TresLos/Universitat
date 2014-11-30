#include "../magia.h"

int main (void)
{
	double *x, *f;
	int n;
	printf ("\nEntra la n:\n");
		scanf ("%d", &n);
	printf ("\nEntreu les x's:\n");
	x = GVM (n);
	printf ("\nEntreu les f's:\n");
	f = GVM (n);
/* Entrada necessaria */

	difdiv (n, x, f);
	int i;
	for (i = 1; i < 20; i++)
		printf ("%3.1lf %.25lf\n", i/2., horner (i/2., n, x, f));
	return 0;
}
