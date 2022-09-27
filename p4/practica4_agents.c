#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "practica4.h"

double f(double x) {
	double x1 = pow(x,2);
	double result = 1 / (1+x1);

	return result;
}

void dispatcher( int workpipe, int numwp, long ndiv) {
	struct procesos st_pkg;
	double tam_trap;
	double x1 = 0;
	long div_pkg, resto = 0;
	
	div_pkg = ndiv/numwp;
	resto = ndiv%numwp;

	tam_trap = 1/(double)ndiv;
	
	for(int i = 0; i < numwp; i++) {	
		st_pkg.x1 = x1;
		st_pkg.tam_trap = tam_trap;
		if(resto > 0) {
			st_pkg.div_pkg = div_pkg+1;
			resto--;
		}
		else
			st_pkg.div_pkg = div_pkg;
		
		st_pkg.f = f;

		write(workpipe, &st_pkg, sizeof(struct procesos));
	
		x1 += st_pkg.div_pkg*st_pkg.tam_trap;	
	}
}

void worker( int workpipe, int resultpipe) {
	struct procesos st_pkg;
	double y1, y2, x1=0, x2=0;
	double area = 0;
	
	while(read(workpipe, &st_pkg, sizeof(struct procesos)) > 0) {
		x1 = st_pkg.x1;
		for(int i = 0; i < st_pkg.div_pkg; i ++){
			x2 = x1 + st_pkg.tam_trap;
			
			y1 = f(x1);
			y2 = f(x2);

			area += ((y2+y1)*(x2-x1))/2;
			
			x1 = x2;
		}
		
		write(resultpipe, &area, sizeof(double));
		area = 0;
	}
}

void gatherer( int resultpipe) {
	double area, area_total;
	while(read(resultpipe, &area, sizeof(double)) > 0) {
		area_total += area;
	}
	
	area_total *= 4;

	printf("Valor calculado: %.15f\n", area_total);
}
