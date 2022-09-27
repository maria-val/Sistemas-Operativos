CFLAGS = -g -Wall

all: practica4_pimc practica4_pipes practica4_dispatcher practica4_worker practica4_gatherer

practica4_pimc: practica4_pimc.c
	gcc $(CFLAGS) practica4_pimc.c -o practica4_pimc -lm

practica4_pipes: practica4_pipes.o practica4_agents.o
	gcc practica4_pipes.o practica4_agents.o -o practica4_pipes -lm

practica4_dispatcher: practica4_dispatcher.o practica4_agents.o
	gcc practica4_dispatcher.o practica4_agents.o -o practica4_dispatcher -lm

practica4_worker: practica4_worker.o practica4_agents.o
	gcc practica4_worker.o practica4_agents.o -o practica4_worker -lm

practica4_gatherer: practica4_gatherer.o practica4_agents.o
	gcc practica4_gatherer.o practica4_agents.o -o practica4_gatherer -lm

run_fifos: 
	mkfifo trabajo
	mkfifo resultados
	./practica4_dispatcher 100000000 100 trabajo &
	./practica4_worker trabajo resultados &
	./practica4_worker trabajo resultados &
	./practica4_worker trabajo resultados &
	./practica4_gatherer resultados

clean:
	rm -f *.o
	rm -f practica4_pimc
	rm -f practica4_pipes
	rm -f practica4_dispatcher
	rm -f practica4_worker
	rm -f practica4_gatherer
	rm -f trabajo
	rm -f resultados


