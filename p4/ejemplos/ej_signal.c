#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mysighandler( int n);

int main( int argc, char* argv[]){

	signal( SIGINT, mysighandler); 	//cuando haya una interrupción desde teclado
					//entraremos al manejador de señales 
	while( 1);			//(la función mysighandler)

	return 0;
}

void mysighandler( int n){

	printf("It is a good day to die... but the day is not yet over.\n");
	signal( SIGINT, SIG_DFL); 	//cuando se imprima el mensaje anterior, 
					//el sistema espera a que ocurra otra
					//interrupción y manejará la señal con el 
					//comportamiento por defecto, es decir, el
					//programa terminará
}					

						
