#include <stdio.h>
#include <stdlib.h>
#include "practica3.h"
#include "integra_th.h"

int main(int argc, char *argv[]){
	
	double res;
      	double x1 = 0;
     	double x2 = 1;
	long nstep;
	int nthreads;

	if(argc != 3){
		printf("Argumentos incorrectos. Uso: \n./practica3 <numero de hilos> <numero de divisiones>\n");
		exit(-1);
	}

	nstep = atol(argv[2]);
	nthreads = atoi(argv[1]);
	
	if(nthreads < 1){
		printf("Error: el numero de hilos tiene que ser mayor que 1\n");
		exit(-1);
	}


	integra_trap_th(&res, x1, x2, nstep, nthreads, f);
	
	res = res * 4;

	printf("Valor calculado: %.14lf\n", res);
}
