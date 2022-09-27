CFLAGS = -Wall

all: practica2_mostrar practica2_std practica2_mmap 

practica2_mostrar: muestranotas.o
	gcc $(CFLAGS) muestranotas.o -o practica2_mostrar

practica2_std: ordenanotas_std.o practica2.o
	gcc $(CFLAGS) ordenanotas_std.o practica2.o -o practica2_std

practica2_mmap: ordenanotas_mmap.o practica2.o
	gcc $(CFLAGS) ordenanotas_mmap.o practica2.o -o practica2_mmap

muestranotas.o: muestranotas.c practica2.h
	gcc $(CFLAGS) -c muestranotas.c

ordenanotas_std.o: ordenanotas_std.c practica2.h
	gcc $(CFLAGS) -c ordenanotas_std.c

ordenanotas_mmap.o: ordenanotas_mmap.c practica2.h
	gcc $(CFLAGS) -c ordenanotas_mmap.c

practica2.o: practica2.c practica2.h
	gcc $(CFLAGS) -c practica2.c

datos: datos.tgz
	tar -xf datos.tgz

clean:
	rm -f *.o
	rm -f datos*.bin
	rm -f ._datos*.bin
	rm -f practica2_mostrar
	rm -f practica2_std
	rm -f practica2_mmap
	
