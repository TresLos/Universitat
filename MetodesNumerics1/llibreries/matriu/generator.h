/* Generador de vectors i matrius, aleatories o no. */
/*
   GMB	Genera Matriu Buida
   GMZ	Genera Matriu Zeros
   GMM	Genera Matriu Manual
   GMA	Genera Matriu Aleatoria
   FM	Free   Matrix

   GVB	Genera Vector Buit
   GVZ	Genera Vector Zeros
   GVM	Genera Vector Manual
   GVA	Genera Vector Aleatori
   FV	Free   Vector
*/

/**
  * Allibera memoria d'una matriu
  */
void FM (double **a, int m, int n)
{
	int i;
	for (i = 0; i < m; i++)
		free (a[i]);
	free (a);
}

/**
  * Allibera memoria d'un vector
  */
void FV (double *v, int m) { free (v); }

/**
  * Genera la Matriu Buida
  *
  * m, files
  * n, columnes
  *
  * @return Matriu buida
  */
double **GMB (int m, int n)
{
	int i;
	double **a = (double **) malloc (m * sizeof (double *));

	if (a == NULL)
	{
		printf ("Error en GMB, no hi ha espai");
		exit (1);
	}

	for (i = 0; i < m; i++)
	{
		a[i] = (double *) malloc (n * sizeof (double *));
		if (a[i] == NULL)
		{
			FM (a, i, i);
			printf ("Error en GMB, no hi ha espai /a[i], em alliberat el que em creat ara.");
			exit (1);
		}
	}
	return a;
}

/**
  * Genera Vector Buit
  *
  * n, files (n x 1)
  *
  * @return Vector buit
  */
double *GVB (int n)
{
	double *a = (double *) malloc (n * sizeof (double *));
	if (a == NULL)
	{
		printf ("Error en GVB, no hi ha espai");
		exit (1);
	}
	return a;
}

/**
  * Genera la Matriu amb Zeros
  *
  * m, files
  * n, columnes
  *
  * @return Matriu buida
  */
double **GMZ (int m, int n)
{
	int i;
	double **a = (double **) calloc (m, sizeof (double *));

	if (a == NULL)
	{
		printf ("Error en GMB, no hi ha espai");
		exit (1);
	}

	for (i = 0; i < m; i++)
	{
		a[i] = (double *) calloc (n, sizeof (double *));
		if (a[i] == NULL)
		{
			FM (a, i, i);
			printf ("Error en GMZ, no hi ha espai /a[i], em alliberat el que em creat ara.");
			exit (1);
		}
	}
	return a;
}

/**
  * Genera Vector amb zeros
  *
  * n, files (n x 1)
  *
  * @return Vector buit
  */
double *GVZ (int n)
{
	double *a = (double *) calloc (n, sizeof (double *));
	if (a == NULL)
	{
		printf ("Error en GVZ, no hi ha espai");
		exit (1);
	}
	return a;
}

/**
  * Genera la Matriu de forma Manual
  *
  * m, files
  * n, columnes
  *
  * @param Matriu creada manualment
  * aparentment funciona correctament
  */
double **GMM (int m, int n)
{
	double **a = GMB (m, n);

	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf ("%le" , &a[i][j]);
	}
	return a;
}

/**
  * Genera el Vector de forma Manual
  *
  * n x 1
  * Crec que es correcte dir-ho aixi
  *
  * @param Vector creat manualment
  * aparentment funciona correctament
  */
double *GVM (n)
{
	double *a = (double *) malloc (n * sizeof (double *));
	int i;
	for (i = 0; i < n; i++)
		scanf ("%le", &a[i]);
	return a;
}

/**
  * Genera una matriu aleatoria
  *
  * max, el valor maxim de la matriu
  * min, " minim
  * e, la matriu que generarem "teoricament aqui sense inicialitzar // &Matriu
  * m, files
  * n, columnes
  *
  * rand => |max - min| rand ()/ RAND_MAX + min
  * aparentment funciona correctament
  * fa magia, desconec el motiu de multiplicar per 10
  */
void GMA (double max, double min, double ***e, int m, int n)
{
	double **a = GMB (m, n);
	int i, j;
	max *= 10; // no entenc el perque els necessito.
	min *= 10; // sense ells no obtinc el resultat desitjat
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			a[i][j] = (fabs (max - min) * rand ()) / (double) RAND_MAX + min;
	}
	*e = a;
}

/**
  * Genera un vector aleatori
  *
  * max, valor maxim
  * min, valor minim
  * e, vector que generem, "teoricament sense inicialitzar" // &Vector
  * n, files (n x 1)
  * aparentment funciona correctament
  * fa magia, desconec el motiu de multiplicar per 10
  */
void GVA (double max, double min, double **e, int n)
{
	int i;
	max *= 10;
	min *= 10;
	double *a = GVB (n);
	for (i = 0; i < n; i++)
		a[i] = (fabs (max - min) * rand ()) / (double) RAND_MAX + min;
	*e = a;
}
