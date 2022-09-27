#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integra_th.h"

int main (int argc, char* argv[]) {

	if(argc != 4){
		printf("Argumentos incorrectos. Uso: \n./practica3_test <x inicial> <x final> <numero de divisiones>");
		exit(-1);
	}
	
	double res;	
	double x1 = atof(argv[1]);
        double x2 = atof(argv[2]);
        long nstep = atol(argv[3]);
       	int nthreads = 2;

	integra_trap_th(&res, x1, x2, nstep, nthreads, exp);

	printf("Valor calculado: %.14lf\n", res);
}
