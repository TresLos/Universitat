/* Encarregat de tenir totes les llibreries de les interpolacions polinomiques                                            */
/*                                                                                                                        */
/*                                                                                                                        */
/*                                                                                                                        */
/*                                                                                                                        */
/*
Diferencies divisibles ``Newton''
ok	difdiv		Interpolacio, substitueix la f
ok	difdivC		Lo mateix, pero aqui la sortida queda a c

Obtenir resultats
ok	horner

Obtenir abscisses
ok	aEq		Abscisses equidistants
	aCy		Abscisses de Chebyshev

Imprimir en fitxer out
ok	writeFile	Imprimeix al fitxer out.gp
*/

void
difdiv ( int n, double *x, double *f )
{
	int i, j;
	for (i = 0; i < n -1; i++)
		for (j = n -1; j > i; j--)
			f[j] = (f[j] - f[j -1]) / (x[j] - x[j - i -1]);
}
void
difdivC ( int n, double *x, double *f, double **ct )
{
	int i, j;
	double *c;
	c = CV (n, f);
	for (j = 0; j < n; j++)
		c[j] = (f[j] - f[j -1]) / (x[j] - x[j -1]);
	for (i = 1; i < n -1; i++)
		for (j = n -1; j > i; j--)
			c[j] = (c[j] - c[j -1]) / (x[j] - x[j - i -1]);
	*ct = c;
}

/*
   r ← cn,
   r ← r(z − xi) + ci, ∀i = n − 1, n − 2, . . . , 1, 0
   
   la c, es la interpolacio de f

   f(z) = r
*/
double
horner( double z, int n, double *x, double *c )
{
	int i;
	double r = c[n -1];
	for (i = n -2; i >= 0; i--)
		r = r*(z - x[i]) + c[i];
	return r;
}



/*
   n, dimencio total desitjada

   min, es el minim on vols comenzar
   max, es el maxim on vols acabar

   x, es on escriura els valors
*/
double *
aEq ( int n, double min, double max )
{
	double *x, h;
	int i;
	h = fabs (max - min)/(n-1);
	x = DIV (n);
	for (i = 0; i < n; i++)
		x[i] = min + i*h;
	return x;
}
double *
aCy ( int n, double min, double max )
{
	double *x;
	int i;
	x = DIV (n);
	for (i = 0; i < n; i++)
		x[i] = cos ( (PI*(2*i +1))/(2*(n +1)) );
	return x;
}

/*
   h, es l'increment equidistant
   min, es el minim on vols comenzar
   max, es el maxim on vols acabar
*/
void
writeFile ( int n, double h, double min, double max, double *x, double *c )
{
	FILE *F;
	double i;
/* Extencio del gnuploat = .gp */
	F = fopen ("out.gp", "w");
	for (i = min; i <= max; i+=h)
		fprintf (F, "%.20le\t%.20le\n", i, horner (i, n, x, c));
}
