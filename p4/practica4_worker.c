#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "practica4.h"

int main(int argc, char *argv[]){
	int fd_work = open(argv[1], O_RDONLY);
	int fd_results = open(argv[2], O_WRONLY);

	worker(fd_work, fd_results);

	close(fd_work);
	close(fd_results);

	return 0;
}
