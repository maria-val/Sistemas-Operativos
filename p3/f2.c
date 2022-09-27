#include <stdio.h>
#include <math.h>
#include "practica3.h"

double f(double x){
	
	double x_cuadrado = pow(x,2);

	double result = 1 / (1+x_cuadrado);
	
	return result;
}
