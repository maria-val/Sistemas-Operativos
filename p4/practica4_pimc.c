#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <signal.h>

double result, correct = 0;
int seed, iter_count;

void sig_handler(int n, siginfo_t* info, void* context){
	result = correct/iter_count;
	result = result * 4;

	if(n == SIGALRM){
		printf("Finalizado por timeout tras %d iteraciones.\n", iter_count);
	      	printf("Valor calculado: %f\n", result);
        	exit(-1);
	}
	if(n == SIGINT){
		printf("Finalizado por interrupción.\n");
		printf("Valor calculado: %f\n", result);
	        exit(-1);
	}
	if(n == SIGUSR1){
		printf("Resultado parcial solicitado (SIGUSR1 de %d)\n", info->si_pid);
		printf("Valor calculado hasta ahora: %f\n", result);
	}
}

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Número de argumentos inválido");
		exit(-1);
	}

	double x, y, radio;
	time_t sec;
	int alarm_time, iter;	
	
	struct sigaction st_sig;
	st_sig.sa_sigaction = sig_handler;
	st_sig.sa_flags = SA_SIGINFO;
	
	iter = atoi(argv[1]);
	alarm_time = atoi(argv[2]);
	
	seed = time(&sec);
	srand48(seed);
	
	sigaction(SIGINT, &st_sig, NULL);
	sigaction(SIGUSR1, &st_sig, NULL);
	sigaction(SIGALRM, &st_sig, NULL);
	alarm(alarm_time);

	printf("Proceso lanzado (PID=%d)\n", getpid());

	for(int i = 0; i < iter; i++){
		x = drand48();
		y = drand48();
		
       		radio = sqrt(pow(x,2) + pow(y,2));		
		
		if(radio <= 1)
			correct++;

		iter_count++;
	}
	
	result = correct/iter_count;
	result = result * 4;

	printf("Finalizado después de %d iteraciones.\n", iter_count);
	printf("Valor calculado: %f\n", result);	

	return 0;
}
