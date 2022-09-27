#include "practica2.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int ordenanotas(int fd)
{
	struct evaluacion alumnos;
	int intercambios = 0;
	
	struct stat fileStat;
        fstat(fd, &fileStat);
                                   
	int tam_fd = fileStat.st_size;
        int tam_struct = sizeof(struct evaluacion);
        int num_struct = tam_fd/tam_struct;

	for(int i = 0; i < num_struct-1; i++){	
		for(int j = 0; j < num_struct-i-1; j++){
			
			read(fd, &alumnos, sizeof(struct evaluacion));	
			//se guarda en una variable la estructura leida.
			struct evaluacion alum1 = alumnos;		
			read(fd, &alumnos, sizeof(struct evaluacion));
		
			if(alumnos.notamedia > alum1.notamedia){
			//como las dos notas no están ordenadas de manera descendiente,
			//se guarda también la estructura siguiente para luego poder posicionar el 
			//puntero en la anterior estructura leida y hacer el intercambio de datos. 
				struct evaluacion alum2 = alumnos; 
				lseek(fd, -2*sizeof(struct evaluacion), SEEK_CUR);
				write(fd, &alum2, sizeof(struct evaluacion));
			       	write(fd, &alum1, sizeof(struct evaluacion));
				
				intercambios++;
			}
			lseek(fd, -sizeof(struct evaluacion), SEEK_CUR);
		}
		lseek(fd, 0, SEEK_SET); //se vuelve al comienzo del archivo.
	}

	return intercambios;

}

