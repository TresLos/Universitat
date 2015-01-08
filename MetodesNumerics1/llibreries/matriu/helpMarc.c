#include<stdio.h>
#include<stdlib.h>
void randmat (int n, int m, int randmin, int randmax, int **mat)
{
	int i, j, marge=randmax-randmin+1;
	mat=(int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
		mat[i]=(int *) calloc (m,sizeof(int));
	/*posa comprovacions*/
	for(i=1;i<n;i++)
		for(j=0;j<m;j++)
			mat[i][j]=rand()&marge+randmin;
	return;
}
