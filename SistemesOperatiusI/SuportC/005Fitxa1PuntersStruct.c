#include <stdio.h>
#include <stdlib.h>

struct camp
{
	int identificador;
	double valor;
};

int main (void)
{
	int i;
	struct camp *a, *pos, *end;
	a = malloc (sizeof (struct camp) * 5);
	if (!a)
	{
		printf ("No s'ha pogut reservar memòria\n");
		exit (1);
	}
	end = a + 5;
	for (pos = a; pos < end; pos++)
	{
		pos->identificador = 0;
		pos->valor = 0.0;
//		(*pos).identificador = 0;
// El sistema aquest es mes eficient, l'altre el que fa es *(a + i), quan aqui fem *pos, mes directe
	}
	free (a);
	return 0;
}
