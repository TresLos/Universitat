/*                                                                                                                              */
/*                                                                                                                              */
/* Retorna dimencio dels vectors                                                                                                */
int
Llegir (double **xi, double **fi)
{
	double *x, *f;
	printf ("\nEntreu la n:\n");
	scanf ("%d", &n);

	x = DVI (2*(n +1));
	f = DVI (2*(n +1));

	for (i = 0; i < 2*(n +1); i+=2)
	{
		scanf ("%le %le %le", &x[i], &f[i], f[i +1]);
		x[i +1] = x[i];
	}

	*xi = x;
	*fi = f;
	return n;
}



/*
 *	De moment ha saber que faig // Escriure des de ``inconsolata'' // ho diu en anguita // 
 *
 *
 *	m = 2n+1
*/
void difdivherm( int m, double *x, double *f)
{
	printf ("s'ha d'implementar");
}


double *DVI (int n)
{
	double *v;
	v = malloc (n * sizeof (double));
	if (v == NULL)
		exit(EXIT_FAILURE);
	return v;
}
