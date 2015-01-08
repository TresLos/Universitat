#include <stdio.h>
#include <math.h>

/* funciona, lent en executar */
int main (void)
{
	int i = 0;
	while (i < i + 1)
		i++;

	printf ("%d\n", i++);
	printf ("%d\n\n", i);
	return 0;
}
/*
2147483645
2147483646
2147483647
-2147483648
*/
