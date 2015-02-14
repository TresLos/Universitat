#include <stdio.h>
#include <math.h>

double fuk1 (int a) { return sqrt ((double) a); }
double fuk2 (int a) { return log ((double) a); }

int main (void)
{
	double ret;
	double (*mF)(int);
	mF = fuk1;
	printf ("Resultat: %e\n", mF(5));
	mF = fuk2;
	printf ("Resultat: %e\n", mF(5));
}
