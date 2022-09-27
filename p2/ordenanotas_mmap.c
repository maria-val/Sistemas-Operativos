#include "practica2.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int ordenanotas(int fd)
{	
	int intercambios = 0;
	struct evaluacion aux;	//estructura auxiliar utilizada dentro del algoritmo de la burbuja.

	struct stat fileStat;
        fstat(fd, &fileStat);
                                   
	int tam_fd = fileStat.st_size;
        int tam_struct = sizeof(struct evaluacion);
        int num_struct = tam_fd/tam_struct;
	
	//se proyecta todo el archivo en una dirección elegida por el SO en modo de protección 
	//lectura/escritura y con mapeado público para otros procesos.
	struct evaluacion *alumnos = mmap(0, tam_fd, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	if(&alumnos == MAP_FAILED){
		perror("Error proyectando archivo");
		exit(-1);
	}	
	
	for(int i = 0; i < num_struct-1; i++){	
		for(int j = 0; j < num_struct-i-1; j++){
			if(alumnos[j].notamedia < alumnos[j+1].notamedia){
				aux = alumnos[j];
				alumnos[j] = alumnos[j+1];
				alumnos[j+1] = aux;
				
				intercambios++;
			}
		}
	}
	
	munmap(0, tam_fd);	//se deshace la proyección.

	return intercambios;
}

