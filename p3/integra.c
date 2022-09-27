#include <stdio.h>
#include <math.h>
#include "integra.h"

int integra_trap(double *result, double x1, double x2, long nstep, double(*f)(double)) {
	double y1, y2, area;
	double tam_trap = (x2-x1)/nstep;
	
	double x2_aux = x1 + tam_trap;
	
	for(int i=0; i < nstep; i++){
		if(x2_aux > x2)
			x2_aux = x2;

		y1 = f(x1);
		y2 = f(x2_aux);
		area = ((y2 + y1)*(x2_aux - x1))/2;
		
		x1 = x2_aux;
		x2_aux = x2_aux + tam_trap;
		
		*result = *result + area;
	}
	
	return 0;
}
