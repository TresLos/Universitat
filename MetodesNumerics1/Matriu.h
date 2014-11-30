/* declarar inicialitzar vector */
double *DIV ( n )
{
	double *a = (double *) malloc (n * sizeof (double *));
	if (a == NULL)
	{
		printf ("\nError en DIV, no hi ha espai en memoria\n");
		exit (1);
	}
	return a;
}
double *GVM ( n )
{
	double *a = DIV (n);
	int i;
	for (i = 0; i < n; i++)
		scanf ("%le", &a[i]);
	return a;
}

double * CV ( int n, double *v )
{
	int i;
	double *a = DIV (n);
	for (i = n -1; i > -1; i--)
		a[i] = v[i];
	return a;
}


void SV ( int n, double *v )
{
	int i;
	printf ("\nShow vector\n");
	for (i = 0; i < n; i++)
		printf ("%20.3lf", v[i]);
	printf ("\n");
}
