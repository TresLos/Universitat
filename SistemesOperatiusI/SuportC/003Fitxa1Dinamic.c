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
	for (i = 0; i < 5; i++)
		a[i] = 0;
	printf ("sizeof (a) = %d\n", sizeof (a));
	free (a);
	return 0;
}
