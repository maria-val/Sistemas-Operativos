all: hello

hello: hello.o imprime.o
	gcc hello.o imprime.o -o hello

hello.o: hello.c
	gcc -c hello.c

imprime.o: imprime.c
	gcc -c imprime.c

clean:
	rm -f *.o
	rm -f hello
