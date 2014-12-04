#include <stdlib.h>
#include <stdio.h>

#include <llegir.h>


void printV (int n, double *v)
{
	int i;
	for (i = 0; i < n; i++)
		printf ("%le\n", v[i]);
}
int main (void)
{
	double *x, *f;
	Llegir (&x, &f);
return 0;
}
