#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "practica4.h"

int main(int argc, char *argv[]){
	
	if(argc != 4){
		printf("Argumentos incorrectos. Uso: \n./practica4 <num de divisiones> <num work packages> <num de workers>\n");
		exit(-1);
	}
	
	long num_div;
	int num_pkg, num_work;
	int workpipe[2], resultpipe[2];
	
	num_div = atol(argv[1]);
	num_pkg = atoi(argv[2]);
	num_work = atoi(argv[3]);

	pipe(workpipe);
	pipe(resultpipe);
	

	if(fork() == 0) {
		close(workpipe[0]);
		close(resultpipe[0]);
		close(resultpipe[1]);
		dispatcher(workpipe[1], num_pkg, num_div);
		close(workpipe[1]);
		exit(0);
	}
	
	for(int i = 0; i < num_work; i++) {
		if(fork() == 0) {
			close(workpipe[1]);
			close(resultpipe[0]);
			worker(workpipe[0], resultpipe[1]);
			close(workpipe[0]);
			close(resultpipe[1]);
			exit(0);
		}
	}

	if(fork() == 0) {
		close(resultpipe[1]);
		close(workpipe[0]);
		close(workpipe[1]);
		gatherer(resultpipe[0]);
		close(resultpipe[0]);
		exit(0);
	}

	close(workpipe[0]);
	close(workpipe[1]);
	close(resultpipe[0]);
	close(resultpipe[1]);

	while(wait(0) > 0);
}
