#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "practica2.h"

int main(int argc, char* argv[])
{
	struct evaluacion alumnos;
	struct stat fileStat;	//el tipo de estructura que devuelve fstat
	int n = 5; 	//variable de tipo entero para que las notas que se impriman
			//por pantalla tengan un espacio de 5 caracteres.
	
	if(argc != 2){
		printf("Número de argumentos inválido.\n");
		exit(-1);
	}

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("Error al abrir archivo.");
		exit(-1);
	}
	
	fstat(fd, &fileStat);	//se utiliza fstat en este caso para hallar el tamaño del archivo.
	
	int tam_fd = fileStat.st_size;
	int tam_struct = sizeof(struct evaluacion);
	int num_struct = tam_fd/tam_struct;

	for(int i=0; i < num_struct; i++){
		read(fd, &alumnos, sizeof(struct evaluacion));
		
		printf("%10s:%*.2f:%*.2f:%*.2f:%s %s, %s\n", alumnos.id, n, alumnos.nota1p, n, alumnos.nota2p, n, alumnos.notamedia, alumnos.apellido1, alumnos.apellido2, alumnos.nombre);
	}

	close(fd);

	return 0;
}
