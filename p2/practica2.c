#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "practica2.h"

int main(int argc, char* argv[])
{
	int t_total, intercambios;
	struct timeval t1, t2;
	
	if(argc != 2){
		printf("Número de argumentos invalido.\n");
		exit(-1);
	}

	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("Error al abrir archivo");
		exit(-1);
	}
	
	gettimeofday(&t1, NULL);
	intercambios = ordenanotas(fd);
	gettimeofday(&t2, NULL);
	
	t_total = 1e6*(t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec);

	printf("Intercambios: %d\n", intercambios);
	printf("Tiempo empleado: %dus\n", t_total);
	
	close(fd);
}
