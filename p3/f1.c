#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "practica3.h"

double f(double x){
		
	double x1 = pow(x,2);
	double ec = 1 - x1;
	double result = sqrt(ec);

	return result;
}
