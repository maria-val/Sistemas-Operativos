CFLAGS = -g -Wall

all: signal sigaction sigaction2 ej_fork ej_exit ej_exec mytest ej_pipe ej_fifo

signal: ej_signal.c
	gcc $(CFLAGS) ej_signal.c -o signal

sigaction: ej_sigaction.c
	gcc $(CFLAGS) ej_sigaction.c -o sigaction

sigaction2: ej_sigaction2.c
	gcc $(CFLAGS) ej_sigaction2.c -o sigaction2

ej_fork: ej_fork.c
	gcc $(CFLAGS) ej_fork.c -o ej_fork

ej_exit: ej_exit.c
	gcc $(CFLAGS) ej_exit.c -o ej_exit

ej_exec: ej_exec.c
	gcc $(CFLAGS) ej_exec.c -o ej_exec

mytest: mytest.c
	gcc $(CFLAGS) mytest.c -o mytest

ej_pipe: ej_pipe.c
	gcc $(CFLAGS) ej_pipe.c -o ej_pipe

ej_fifo: ej_fifo.c
	gcc $(CFLAGS) ej_fifo.c -o ej_fifo

clean: 
	rm -f signal
	rm -f sigaction
	rm -f sigaction2
	rm -f ej_fork
	rm -f ej_exit
	rm -f ej_exec
	rm -f mytest
	rm -f ej_pipe
	rm -f ej_fifo
