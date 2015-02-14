#include <stdio.h>

struct camp
{
	int identificador;
	double valor;
};

int main (void)
{
	int i;
	struct camp a[5];
	printf ("sizeof (struct camp) = %d\n", sizeof (struct camp));
	for (i = 0; i < 5; i++)
	{
		a[i].identificador = 0;
		a[i].valor = 0.0;
	}
	printf ("sizeof (a) = %d\n", sizeof (a));
	return 0;
}
