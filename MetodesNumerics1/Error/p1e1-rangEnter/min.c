#include <stdio.h>
#include <math.h>

/* funcina, lent a executar */
int main (void)
{
	int i = 0;
	while (i > i - 1)
		i--;

	printf ("%d\n", i--);
	printf ("%d\n\n", i);
	return 0;
}
// %s/+/-/g de max.c
/*
-2147483646
-2147483647
-2147483648
2147483647
*/
