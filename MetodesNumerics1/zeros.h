int secant ( double *x0, double *x1, double prec, int iter)
{
	double aux;
	for (iter; iter > 0; iter--)
	{
		aux = *x1;
		*x1 = *x1 - fun (*x1)* (*x1 - *x0)/(fun (*x1) - fun (*x0));
		*x0 = aux;
		if (fabs (*x1 - *x0) < prec && fabs (*x1) < prec)
			return 0;
	}
	return 1;
}

int newton ( double *x, double prec, int iter )
{
	double aux;
	for (iter; iter > 0; iter--)
	{
		aux = *x;
		*x = *x - fun (*x) / der (*x);
		if (fabs (*x - aux) < prec && fabs (*x) < prec)
			return 0;
	}
	return 1;
}
