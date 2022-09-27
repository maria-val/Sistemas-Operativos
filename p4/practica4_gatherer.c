#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "practica4.h"

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_RDONLY);
	gatherer(fd);
	close(fd);

	return 0;
}
