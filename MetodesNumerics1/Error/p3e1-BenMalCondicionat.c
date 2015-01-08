#include <stdio.h>
#include <math.h>

double BenMalCondicionat (double alpha, double x, double c) { return (alpha + 1/c) * exp (c * x) - 1/c; }
void printeja (double alpha, double c, double x)
{
	//double yaprox, yexac;
	int i;
	double j = 1/100.;
	for (i = 1; i < 20; i++)
		printf ("%10le     %10le\n", c + j*i, BenMalCondicionat (alpha, x, c + j * i) - BenMalCondicionat (alpha, x, c));
}

/* Funciona */
int main (void)
{
	double alpha = 1, c = 2, x = 10;
	printf ("\nMostra per 2:\n\n");
	printeja (alpha, c, x);
	c = -2;
	printf ("\nMostra per -2:\n\n");
	printeja (alpha, c, x);

	return 0;
}// Per a -2 dona uns resultats que fan por "Mal plantejat"
