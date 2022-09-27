#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "practica4.h"

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Argumentos incorrectos. Uso: \n./practica4_dispatcher <num div> <num work packages> <work fifo>\n");
		exit(-1);
	}
	
	long num_div = atol(argv[1]);
	int num_pkg = atoi(argv[2]);

	int fd = open(argv[3], O_WRONLY);
	dispatcher(fd, num_pkg, num_div);
	close(fd);

	return 0;
}
