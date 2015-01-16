#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                            Elemental
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

/**
  * DIV - Declara sense Informacio la Variable
  *
  * @param n
  *	Longitud del vector
  * @return
  *	Un vector vuit de la longitud demanada
  */
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
/**
  * GVM - Genera el Vector de forma Manual
  *
  * @param n
  *	Es per definir la dimensio maxima
  */
double *GVM (n)
{
	double *a = DIV (n);
	int i;

	for (i = 0; i < n; i++)
		scanf ("%le", &a[i]);
	return a;
}

/**
  * HGVM - ajuda (Help) Generador de Vector de forma Manual
  *
  * @param *v
  *	Vector que contindra el resultat
  * @return
  *	Saber la dimensio del mateix vector
  */
int HGVM (double **v)
{
	int n;
	printf ("\nEntreu la dimensio del vector:\n");
	scanf ("%d", &n);
	printf ("\nEntreu els valors del vector\n");
	*v = GVM (n);
	return n;
}

/**
  * CV - Copia el Vector
  *
  * @param n
  *	Longitud del vector
  * @param *v
  *	Vector que vol ser copiat
  * @return
  *	Un vector independent amb el mateix contingut
  */
double * CV ( int n, double *v )
{
	int i;
	double *a = DIV (n);

	for (i = n -1; i > -1; i--)
		a[i] = v[i];
	return a;
}


/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                             Demanat
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

/**
  * difdiv - mètode de les diferències dividides
  *
  * @param n
  *	Longitud del vector
  * @param *x
  *	Posicio de la funcio
  * @param *f
  *	Valor de la funcio, es on guardem la solucio
  */
void difdiv ( int n, double *x, double *f )
{
	int i, j;
/* Enunciat: cal que totes les abscisses xi estiguin en ordre estrictament creixent. */
	for (i = 1; i < n; i++)
		if (x[i] < x[i -1])
		{
/* Curiosament, ens ha demostrat el profesor que l'odre no importava */
			printf ("\nCom diu l'enunciat de l'entrega 8, com que no es estrictament creixent, no podem fer l'operacio demanada\n");
			exit (1);
		}

	for (i = 0; i < n -1; i++)
		for (j = n -1; j > i; j--)
			f[j] = (f[j] - f[j -1]) / (x[j] - x[j - i -1]);
}

/**
  * horner - mètode de Horner generalitzat
  *
  * @param z
  *	El punt el que se vol treure el valor de la funcio
  * @param n
  *	Dimencio dels valors
  * @param *x
  *	Posicio de punts calculats
  * @param *c
  *	Valors dels punts en la funcio
  * @return
  *	p(z)
  */
double horner( double z, int n, double *x, double *c )
{
	int i;
	double r;
	r = c[n -1];

	for (i = n -2; i >= 0; i--)
		r = r*(z - x[i]) + c[i];
	return r;
}

/**
  * polinomi interpolador d’Hermite
  */
void difdivherm( int n, double *tx, double *tf, double *g )
{
	int i, j;
	double *x, *f;
	x = DIV (2 * n);
	f = DIV (2 * n);
	for (i = 0; i < 2*n; i+=2)
	{
		x[i] = tx[i];
		x[i +1] = tx[i];
		f[i estic per aqui, no se que he de fer :)
	}
}


/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                             In Out
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
/**
  * writeFile - On vols que escrigui "fitxer"
  *
  * @param n
  *	Dimensio *x i *c
  * @param h
  *	Distancia en que vols calcular cada punt
  * @param min
  *	Valor inicial
  * @param max
  *	Valor final
  * @param *x
  *	Vector de les posicions
  * @param *c
  *	Vector del polinomi obtingut per diferencies dividides
*/
void
writeFile ( int n, double h, double min, double max, double *x, double *c )
{
	FILE *F;
	double i;
/* Extencio del gnuploat = .gp */
	F = fopen ("out.gp", "w");
	for (i = min; i <= max; i+=h)
		fprintf (F, "%.5le\t%.20le\n", i, horner (i, n, x, c));
	fclose (F);
}


/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                             Ajudat
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
int difdivherm(int m, double *x, double *f){
  int i, k, b=1;
  double v, tol=1e-10;
  /*k=1 primer pas*/
  for(i=m-1;i>=2;i--){
    if(b!=1){
      v=x[i]-x[i-1];
      if(v<tol){
      return 1;
      }
      f[i]=(f[i]-f[i-2]/v);
    }
    b=-b;
  }
  /* k>=2 */
  for(k=2;k<m;k++){
    for(i=m-1;i>=k;i--){
      v=x[i]-x[i-k];
      if(v<tol){
	return 1;
      }
      f[i]=(f[i]-f[i-1])/v;
    }
  }
  return 0;
}
