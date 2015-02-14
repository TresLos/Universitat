#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i, *a;
	a = malloc (sizeof (int) * 5);
	if (a == NULL)
	{
		printf ("No s'ha pogut reservar memòria\n");
		exit (1);
	}
	printf ("Comenza a zeros\n");
	for (i = 100; i < 200; i++)
		a[i] = 0;
	free (a);
	return 0;
}
