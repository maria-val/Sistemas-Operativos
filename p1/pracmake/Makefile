CFLAGS = -Wall

all: factorial
	
factorial: factorial.o factprint.o factfun.o
	gcc $(CFLAGS) factorial.o factprint.o factfun.o -o factorial

factorial.o: factorial.c factprint.h 
	gcc $(CFLAGS) -c factorial.c

factprint.o: factprint.c factfun.h
	gcc $(CFLAGS) -c factprint.c

factfun.o: factfun.c 
	gcc $(CFLAGS) -c factfun.c

clean:
	rm -f *.o
	rm -f factorial
