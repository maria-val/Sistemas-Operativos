#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char* argv[]){

	 int n, pipefd[2];

	 pipe( pipefd);

	 if( fork() != 0){

		close( pipefd[1]);		//el padre cierra el extremo de escritura
		while( read( pipefd[0], &n, sizeof( int) ) > 0) //cuando el hijo cierra el extremo de escritura, 
			 		//el padre comienza a leer (se queda bloqueado mientras el hijo escribe)
			printf("Recibido: %d\n", n);
		printf("Se ha cerrado el otro lado del pipe. Finalizando.\n");
		close( pipefd[0]);		//el padre cierra el extremo de lectura
		printf("Exit padre\n");
		exit(0);
	 } 
	 else {

		close( pipefd[0]);		//el hijo cierra el extremo de lectura
		for( n = 2; n < 7; n++){
		 	write( pipefd[1], &n, sizeof( int));
		 //	sleep( 1);
		}
		close( pipefd[1]);
		printf("Exit hijo\n");
                exit(0);
         
	 }
	 
	 return 0;
}
