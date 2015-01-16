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
		if (x[i] > x[i -1])
		{
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
