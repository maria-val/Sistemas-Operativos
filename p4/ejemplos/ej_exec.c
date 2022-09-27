#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int  argc, char* argv[]){

	char* myargv[] = { "mytest", "Una", "dola", "tela", "catola", NULL};
	char* myenv[] = { NULL};

	printf("Me. (PID: %d)\n", getpid() );

	if( execve( myargv[ 0], myargv, myenv) == -1){
		perror( "Error lanzando el programa de ejemplo.");
		exit( -1);
	}

	return 0;
}
