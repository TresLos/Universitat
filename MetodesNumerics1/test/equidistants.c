#include "../magia.h"

#define n 9

double
fun (double x)
{return 1./ (25*x*x + 1);}

int main (void)
{
	double *x, *f;
	int i;
	x = aEq (n, -1., 1. );
/* fins aqui tot funciona */
	f = DIV (n);
	for (i = 0; i < n; i++)
		f[i] = fun (x[i]);
	difdiv (n, x, f); /* generat el polinomi */
	writeFile (n, 0.001, -1, 1, x, f);
	return 0;
}
