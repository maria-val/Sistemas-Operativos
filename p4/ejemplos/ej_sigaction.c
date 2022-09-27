#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mysighandler( int n);

int main( int argc, char* argv[]){

	struct sigaction a;

	a.sa_handler = mysighandler;	//se asigna la función de manejo
	sigemptyset( &a.sa_mask);	//esta función inicia una máscara de señales vacía
	a.sa_flags = 0;

	sigaction( SIGINT, &a, NULL); 	//se maneja la interrupción por teclado con
					//todos los datos guardados en la estructura
	while(1);			//sin guardar la acción anteriormente registrada

	return 0;
}

void mysighandler( int n){

	printf("It is a good day to die... but the day is not yet over.\n");
	signal( SIGINT, SIG_DFL);
}
