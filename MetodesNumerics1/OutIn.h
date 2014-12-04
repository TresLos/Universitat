/*
   De interpolar

   h, es l'increment equidistant
   min, es el minim on vols comenzar
   max, es el maxim on vols acabar
*/
void
writeFile ( int n, double h, double min, double max, double *x, double *c )
{
	FILE *F;
	double i;
/* Extencio del gnuploat = .gp */
	F = fopen ("out.gp", "w");
	for (i = min; i <= max; i+=h)
		fp;rintf (F, "%.20le\t%.20le\n", i, horner (i, n, x, c));
	fclose (F);
}
