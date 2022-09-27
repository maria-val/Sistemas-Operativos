CFLAGS = -g -Wall

all: practica3_test  practica3_1 practica3_2 practica3_test_th

practica3_test_th: practica3_test_th.o integra_th.o
	gcc practica3_test_th.o integra_th.o -o practica3_test_th -lpthread -lm

practica3_test_th.o: practica3_test_th.c integra_th.h
	gcc $(CFLAGS) -c practica3_test_th.c -lpthread -lm

integra_th.o:integra_th.c integra_th.h
	gcc $(CFLAGS) -c integra_th.c -lpthread

practica3_2: practica3.o integra_th.o f2.o
	gcc practica3.o integra_th.o f2.o -o practica3_2 -lm -lpthread

f2.o: f2.c practica3.h
	gcc $(CFLAGS) -c f2.c -lm

practica3_1: practica3.o integra_th.o f1.o
	gcc practica3.o integra_th.o f1.o -o practica3_1 -lm -lpthread

practica3.o: practica3.c integra_th.h practica3.h
	gcc $(CFLAGS) -c practica3.c -lm

f1.o: f1.c practica3.h
	gcc $(CFLAGS) -c f1.c -lm

practica3_test: practica3_test.o integra.o
	gcc practica3_test.o integra.o -o practica3_test -lm

practica3_test.o: practica3_test.c integra.h 
	gcc $(CFLAGS) -c practica3_test.c -lm

integra.o: integra.c integra.h
	gcc $(CFLAGS) -c integra.c -lm

clean: 
	rm -f *.o
	rm -f practica3_test
	rm -f practica3_1
	rm -f practica3_2
	rm -f practica3_test_th
