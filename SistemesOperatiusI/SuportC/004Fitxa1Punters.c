#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *a, *pos, *end;
	a = malloc (sizeof (int) * 5);
	if (a == NULL)
	{
		printf ("No s'ha pogut reservar memòria\n");
		exit (1);
	}
	end = a + 5;
	for (pos = a; pos < end; pos++)
	{
		printf ("pos = %d\n", pos);
		*pos = 0;
	}
	free (a);
	return 0;
}
