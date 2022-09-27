#include <stdio.h>
#include <pthread.h>
#include "integra_th.h"

double area_traps = 0;
pthread_mutex_t lock;

void * func_threads(void *arg){	
	struct thread st_hilo = *((struct thread *)arg);
	double y1, y2;
	double x2_aux = st_hilo.x1 + st_hilo.tam_trap;
	double area;
	
	for(int i = 0; i < st_hilo.nstep_hilo; i ++){
	   
	    	if(x2_aux > st_hilo.x2)
                        x2_aux = st_hilo.x2;

		y1 = st_hilo.f(st_hilo.x1);
		y2 = st_hilo.f(x2_aux);

		area += ((y2 + y1)*(x2_aux - st_hilo.x1))/2;	
		
		st_hilo.x1 = x2_aux;
                x2_aux += st_hilo.tam_trap;
	}

	pthread_mutex_lock(&lock);
	area_traps += area;	
	pthread_mutex_unlock(&lock);
	
	return 0;
}

int integra_trap_th(double *result, double x1, double x2, long nstep, int nthreads, double(*f)(double)){
	pthread_mutex_init(&lock, NULL);

	struct thread st_hilo[nthreads];
	pthread_t hilo[nthreads];
	double tam_trap = (x2-x1)/nstep;
	
	for(int i = 0; i < nthreads; i++){
		if(nstep % nthreads != 0){
			if(i%2 == 0)
				st_hilo[i].nstep_hilo = nstep/nthreads;
				
			else
				st_hilo[i].nstep_hilo = (nstep/nthreads) + 1;
		}
		else 
			st_hilo[i].nstep_hilo = nstep/nthreads;

		st_hilo[i].tam_trap = tam_trap;
		st_hilo[i].x2 = x2;	
		st_hilo[i].x1 = x1;
		st_hilo[i].f = f;
		st_hilo[i].nstep = nstep;
		st_hilo[i].nthreads = nthreads;
		
		pthread_create(&hilo[i], NULL, func_threads, &st_hilo[i]);
		x1 += tam_trap*st_hilo[i].nstep_hilo;
	}

	for(int i = 0; i < nthreads; i++){
		pthread_join(hilo[i], NULL);
	}
	
	pthread_mutex_destroy(&lock);
	*result = area_traps;
	return 0;
}
