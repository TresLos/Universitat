#include <stdio.h>
#include <math.h>

#include "magia.h"

double DoubleRecursiu	(double xn1, double xn2)	{ return 10./3 * xn1 - xn2; }
float FloatRecursiu	(float xn1, float xn2)		{ return 10./3 * xn1 - xn2; }
double DoubleDirecte (int n, double x0, double x1) { return 3/8. * (3 * x0 - x1) * pow (1/3., n) + 1/8.*(3*x1 - x0)*pow(3,n); }

/* funciona, asquerosament gran */
int main (void)
{
// Valors que donem per a operar per comenzar
	int i, n = 50;
	double x0 = 1, x1 = 1/3.;

	double xDirecte, xDoubleRecursiu = x1, xDoubleRecursiu1 = x0, xDoubleTmp;
	float xFloat = (float) x1, xFloat1 = (float) x0, xFloatTmp;

	double errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu;
	float errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu;

	printf ("   i   Directe               Float               Err Abs               Err Relatiu               Double               Err Abs               Err Relatiu\n");

	for (i = 0; i < n; i++)
	{
		xDirecte = DoubleDirecte (i, x0, x1);

		xDoubleTmp		= DoubleRecursiu (xDoubleRecursiu, xDoubleRecursiu1);
		xDoubleRecursiu1	= xDoubleRecursiu;
		xDoubleRecursiu		= xDoubleTmp;
		errorAbsolutDdoubleRecursiu	= xDoubleRecursiu - xDirecte;
		errorRelatiuDoubleRecursiu	= errorAbsolutDdoubleRecursiu / xDirecte;

		xFloatTmp		= FloatRecursiu (xFloat, xFloat1);
		xFloat1			= xFloat;
		xFloat			= xFloatTmp;
		errorAbolutFloatRelatiu	= xFloat - xDirecte;
		errorRelatiuFloatRecursiu	= errorAbolutFloatRelatiu / xDirecte;

		printf ("%3d   %15.10le     %15.10le     %15.10le     %15.10le     %15.10le     %15.10le     %15.10le\n", i, xDirecte, xFloat, errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu, xDoubleRecursiu, errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu);
	}
	return 0;
}
