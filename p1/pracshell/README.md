# Sistemas Operativos - Práctica 1 - shell

## Ejercicios básicos con la `shell`

A continuación se presentan unos ejercicios básicos de manejo de la línea de
órdenes, que van incrementándose en dificultad, que deberán realizarse con los
datos contenidos en el repositorio proporcionado; concretamente desde dentro
del directorio `p1`.

La realización de estos ejercicios no se evalúa ni influye en la nota obtenida
en la práctica 1, sino que es una autoevaluación para el alumno y una forma de
tener una referencia de lo aprendido. La dificultad de las preguntas tampoco es
representativa de la dificultad de las preguntas que pueden aparecer en la
evaluación PL1.

Debajo de cada ejercicio propuesto, editando el presente documento **desde la 
consola**, se deberá indicar:

- El comando o comandos que el alumno ha empleado para conseguir lo propuesto
  en cada ejercicio. 
- (Opcional) El resultado por pantalla, si lo hay.

Se recomienda que si el alumno no tiene aún conocimientos suficientes para
hacerlo de otra forma, mantenga abiertas dos consolas; una donde realizar los
ejercicios y otra donde pueda editar este documento. Se insiste en que la edición 
debe ser **desde la consola**, y no desde la web de GitHub ya que de otra manera 
puede tener problemas al hacer commit del repositorio.

Las órdenes pueden ser simples o estar compuestas de varios comandos empleando
tuberías, o utilizar redirecciones.

Los primeros ejercicios se dan con sus respuestas, a modo de ejemplo sobre cómo
deben responderse el resto de ejercicios.

1. Abra una consola y, desde el directorio donde haya clonado el repositorio,
cambie el directorio de trabajo a `labssoo22-alumno/p1` (el nombre exacto
dependerá de cada alumno).
    
    
		cd Repositorio/labssoo22-maria-dominguez-valdivieso/p1
    
2. Crée un directorio que se llame `pruebas`. Cambie su directorio de trabajo a
este directorio. Muestre el nuevo directorio de trabajo.


		mkdir pruebas 
		cd pruebas 
		pwd 
		home/maria/Repositorio/labssoo22-maria-dominguez-valdivieso/p1/pruebas
    
3. Obtenga desde aquí, empleando una trayectoria relativa, el listado del
directorio `p1/pracshell` que está contenido en el arbol de directorios que ha
descargado el alumno.


		ls ../pracshell 
		test.tgz  
		README.md
    
4. Descomprima los contenidos del archivo `test.tgz` desde el directorio de
trabajo actual, empleando el comando `tar -xzf trayectoria_relativa`. Liste el
contenido del directorio actual.


		tar -xzf ../pracshell/test.tgz 
		ls 
		Chapter01.txt  Chapter05.txt Chapter09.txt  Chapter13.txt  Chapter17.txt 
		Chapter02.txt  Chapter06.txt Chapter10.txt  Chapter14.txt  Chapter18.txt 
		Chapter03.txt  Chapter07.txt Chapter11.txt  Chapter15.txt  Chapter19.txt 
		Chapter04.txt  Chapter08.txt Chapter12.txt  Chapter16.txt
    
5. Como puede observar, se trata de los 19 capítulos de un libro (en realidad,
un fragmento de cada uno), en formato texto plano. Liste los contenidos del
directorio en formato largo, mostrando la lista de archivos ordenada por tamaño
del archivo en bytes, de mayor a menor. (Consulte la página del manual para
encontrar la opción requerida).
		
		ls -lS
		total 76
		-rw-r--r-- 1 maria maria 1381 feb 25  2021 Chapter03.txt
		-rw-r--r-- 1 maria maria 1254 feb 25  2021 Chapter05.txt
		-rw-r--r-- 1 maria maria 1238 feb 25  2021 Chapter13.txt
		-rw-r--r-- 1 maria maria 1237 feb 25  2021 Chapter09.txt
		-rw-r--r-- 1 maria maria 1087 feb 25  2021 Chapter07.txt
		-rw-r--r-- 1 maria maria 1065 feb 25  2021 Chapter04.txt
		-rw-r--r-- 1 maria maria 1026 feb 25  2021 Chapter02.txt
		-rw-r--r-- 1 maria maria  989 feb 25  2021 Chapter11.txt
		-rw-r--r-- 1 maria maria  985 feb 25  2021 Chapter18.txt
		-rw-r--r-- 1 maria maria  904 feb 25  2021 Chapter08.txt
		-rw-r--r-- 1 maria maria  894 feb 25  2021 Chapter12.txt
		-rw-r--r-- 1 maria maria  856 feb 25  2021 Chapter14.txt
		-rw-r--r-- 1 maria maria  772 feb 25  2021 Chapter06.txt
		-rw-r--r-- 1 maria maria  700 feb 25  2021 Chapter01.txt
		-rw-r--r-- 1 maria maria  663 feb 25  2021 Chapter10.txt
		-rw-r--r-- 1 maria maria  659 feb 25  2021 Chapter15.txt
		-rw-r--r-- 1 maria maria  604 feb 25  2021 Chapter19.txt
		-rw-r--r-- 1 maria maria  527 feb 25  2021 Chapter17.txt
		-rw-r--r-- 1 maria maria  458 feb 25  2021 Chapter16.txt

    
6. Liste los contenidos del directorio en formato largo, mostrando la lista de
archivos ordenada por tamaño del archivo en bytes **de menor a mayor**.
(Consulte la página del manual para encontrar la opción requerida).

		ls -lSr
		total 76
		-rw-r--r-- 1 maria maria  458 feb 25  2021 Chapter16.txt
		-rw-r--r-- 1 maria maria  527 feb 25  2021 Chapter17.txt
		-rw-r--r-- 1 maria maria  604 feb 25  2021 Chapter19.txt
		-rw-r--r-- 1 maria maria  659 feb 25  2021 Chapter15.txt
		-rw-r--r-- 1 maria maria  663 feb 25  2021 Chapter10.txt
		-rw-r--r-- 1 maria maria  700 feb 25  2021 Chapter01.txt
		-rw-r--r-- 1 maria maria  772 feb 25  2021 Chapter06.txt
		-rw-r--r-- 1 maria maria  856 feb 25  2021 Chapter14.txt
		-rw-r--r-- 1 maria maria  894 feb 25  2021 Chapter12.txt
		-rw-r--r-- 1 maria maria  904 feb 25  2021 Chapter08.txt
		-rw-r--r-- 1 maria maria  985 feb 25  2021 Chapter18.txt
		-rw-r--r-- 1 maria maria  989 feb 25  2021 Chapter11.txt
		-rw-r--r-- 1 maria maria 1026 feb 25  2021 Chapter02.txt
		-rw-r--r-- 1 maria maria 1065 feb 25  2021 Chapter04.txt
		-rw-r--r-- 1 maria maria 1087 feb 25  2021 Chapter07.txt
		-rw-r--r-- 1 maria maria 1237 feb 25  2021 Chapter09.txt
		-rw-r--r-- 1 maria maria 1238 feb 25  2021 Chapter13.txt
		-rw-r--r-- 1 maria maria 1254 feb 25  2021 Chapter05.txt
		-rw-r--r-- 1 maria maria 1381 feb 25  2021 Chapter03.txt


7. Liste los contenidos del directorio, mostrando la lista de archivos ordenada
por fecha de última modificación, mostrando **primero el más antiguo**.
(Consulte la página del manual para encontrar la opción requerida).

		ls -ltr --full-time
		total 76
		-rw-r--r-- 1 maria maria  700 2021-02-25 18:16:21.000000000 +0100 Chapter01.txt
		-rw-r--r-- 1 maria maria 1026 2021-02-25 18:16:31.000000000 +0100 Chapter02.txt
		-rw-r--r-- 1 maria maria 1381 2021-02-25 18:16:33.000000000 +0100 Chapter03.txt
		-rw-r--r-- 1 maria maria 1065 2021-02-25 18:16:35.000000000 +0100 Chapter04.txt
		-rw-r--r-- 1 maria maria 1254 2021-02-25 18:16:37.000000000 +0100 Chapter05.txt
		-rw-r--r-- 1 maria maria  772 2021-02-25 18:16:38.000000000 +0100 Chapter06.txt
		-rw-r--r-- 1 maria maria 1087 2021-02-25 18:16:40.000000000 +0100 Chapter07.txt
		-rw-r--r-- 1 maria maria  904 2021-02-25 18:16:42.000000000 +0100 Chapter08.txt
		-rw-r--r-- 1 maria maria 1237 2021-02-25 18:16:44.000000000 +0100 Chapter09.txt
		-rw-r--r-- 1 maria maria  663 2021-02-25 18:16:46.000000000 +0100 Chapter10.txt
		-rw-r--r-- 1 maria maria  989 2021-02-25 18:16:48.000000000 +0100 Chapter11.txt
		-rw-r--r-- 1 maria maria  894 2021-02-25 18:16:50.000000000 +0100 Chapter12.txt
		-rw-r--r-- 1 maria maria 1238 2021-02-25 18:16:52.000000000 +0100 Chapter13.txt
		-rw-r--r-- 1 maria maria  856 2021-02-25 18:16:54.000000000 +0100 Chapter14.txt
		-rw-r--r-- 1 maria maria  659 2021-02-25 18:16:58.000000000 +0100 Chapter15.txt
		-rw-r--r-- 1 maria maria  458 2021-02-25 18:17:00.000000000 +0100 Chapter16.txt
		-rw-r--r-- 1 maria maria  527 2021-02-25 18:17:01.000000000 +0100 Chapter17.txt
		-rw-r--r-- 1 maria maria  985 2021-02-25 18:17:03.000000000 +0100 Chapter18.txt
		-rw-r--r-- 1 maria maria  604 2021-02-25 18:17:05.000000000 +0100 Chapter19.txt


8. Cree tres directorios llamados `part1`, `part2` y `part3`. Copie, con un
solo comando y sin cambiar de directorio de trabajo, los capítulos del 1 al 7
en el directorio `part1`.
	
		cp Chapter0[1-7].txt ./part1

    
9. Cambie el directorio de trabajo a `part2` y copie en él, con un solo comando
y sin cambiar de directorio de trabajo, los capítulos del 9 al 14.

		cp ../Chapter{09,1[0-4]}.txt .


10. Sin cambiar de directorio de trabajo (es decir, permaneciendo en `part2`)
copie con un solo comando los capítulos del 15 al 19 en el directorio `part3`.

		cp ../Chapter1[5-9].txt ../part3


11. Vuelva a cambiar el directorio de trabajo al directorio `prueba` y liste
los contenidos del directorio en formato largo, haciendo que se visualice tras
el nombre de cada directorio el caracter `/`.

		ls -lF
		total 88
		-rw-r--r-- 1 maria maria  700 feb 25  2021 Chapter01.txt
		-rw-r--r-- 1 maria maria 1026 feb 25  2021 Chapter02.txt
		-rw-r--r-- 1 maria maria 1381 feb 25  2021 Chapter03.txt
		-rw-r--r-- 1 maria maria 1065 feb 25  2021 Chapter04.txt
		-rw-r--r-- 1 maria maria 1254 feb 25  2021 Chapter05.txt
		-rw-r--r-- 1 maria maria  772 feb 25  2021 Chapter06.txt
		-rw-r--r-- 1 maria maria 1087 feb 25  2021 Chapter07.txt
		-rw-r--r-- 1 maria maria  904 feb 25  2021 Chapter08.txt
		-rw-r--r-- 1 maria maria 1237 feb 25  2021 Chapter09.txt
		-rw-r--r-- 1 maria maria  663 feb 25  2021 Chapter10.txt
		-rw-r--r-- 1 maria maria 1237 feb  8 19:29 Chapter11.txt
		-rw-r--r-- 1 maria maria  894 feb 25  2021 Chapter12.txt
		-rw-r--r-- 1 maria maria 1238 feb 25  2021 Chapter13.txt
		-rw-r--r-- 1 maria maria  856 feb 25  2021 Chapter14.txt
		-rw-r--r-- 1 maria maria  659 feb 25  2021 Chapter15.txt
		-rw-r--r-- 1 maria maria  458 feb 25  2021 Chapter16.txt
		-rw-r--r-- 1 maria maria  527 feb 25  2021 Chapter17.txt
		-rw-r--r-- 1 maria maria  985 feb 25  2021 Chapter18.txt
		-rw-r--r-- 1 maria maria  604 feb 25  2021 Chapter19.txt
		drwxrwxr-x 2 maria maria 4096 feb  8 13:00 part1/
		drwxrwxr-x 2 maria maria 4096 feb  8 19:47 part2/
		drwxrwxr-x 2 maria maria 4096 feb  9 15:05 part3/


12. Sin cambiar de directorio de trabajo, cree un directorio llamado `backup`
en su directorio de conexión y mueva allí todos los archivos de texto del
directorio de trabajo.

		mkdir ~/backup
		mv *.txt ~/backup


13. Muestre por pantalla, con un solo comando y sin cambiar el directorio de
trabajo, los contenidos de los 3 primeros capítulos contenidos en el directorio
`part1`.

		cat part1/Chapter0[1-3].txt


14. Sin cambiar de directorio de trabajo y con una única orden, genere un
archivo en el directorio de trabajo llamado `thehobbit.txt` que contenga el
texto de todos los capítulos almacenados en el directorio `part1`.
	
		cat part1/Chapter*.txt > thehobbit.txt

    
15. Sin cambiar de directorio de trabajo y con una única orden, añada al
archivo anterior los capítulos almacenados en los directorios `part2` y
`part3`. Bonus points si lo hace pasándole a `cat` una única trayectoria.

      		cat part[2-3]/* >> thehobbit.txt


16. Sin cambiar de directorio y con una única orden, genere un archivo
`thehobbit.bak` con los contenidos de todos los capítulos contenidos en el
directorio `backup`creado anteriormente en el directorio de conexión. Compare
este archivo con el archivo `thehobbit.txt` empleando el comando `diff`, y
haciendo que si ambos son iguales este comando lo indique por pantalla.

		cat ~/backup/* > thehobbit.bak
   		diff -s thehobbit.txt thehobbit.bak


17. Averigüe en cuantas lineas aparece la palabra "hobbit" en el archivo
`thehobbit.txt`.

		grep hobbit thehobbit.txt | wc -l
		7


18. Sin cambiar de directorio, averigüe cuantas veces aparece el nombre "Smaug"
en los capítulos contenidos en cada uno de los directorios `part1`, `part2`y
`part3`. No hace falta que sea con un único comando. A continuación, averigüe
con un único comando el total de veces que aparece este nombre entre los tres
directorios.

		grep -c Smaug part[1-3]/*
		part1/Chapter01.txt:0
		part1/Chapter02.txt:0
		part1/Chapter03.txt:1
		part1/Chapter04.txt:0
		part1/Chapter05.txt:0
		part1/Chapter06.txt:0
		part1/Chapter07.txt:0
		part2/Chapter09.txt:0
		part2/Chapter10.txt:0
		part2/Chapter11.txt:0
		part2/Chapter12.txt:0
		part2/Chapter13.txt:2
		part2/Chapter14.txt:1
		part3/Chapter15.txt:0
		part3/Chapter16.txt:0
		part3/Chapter17.txt:0
		part3/Chapter18.txt:0
		part3/Chapter19.txt:0

		grep -o Smaug part[1-3]/* | wc -l
		4


19. Sin cambiar de directorio y con una única orden, averigüe en qué capítulo
de los contenidos en los directorios `part1`, `part2`y `part3` aparece el
nombre "Balin". ¿Sería capaz de conseguir que la respuesta por pantalla fuese
únicamente la trayectoria relativa del archivo?

		grep -l "Balin" part[1-3]/*
		part1/Chapter03.txt
		
		También se puede hacer así:
		grep Balin part[1-3]/*.txt | cut -d : -f 1


20. Borre el archivo `thehobbit.bak`. Borre los directorios `part1`, `part2` y
`part3` junto con sus contenidos, empleando la orden `rm` (consulte la página
del manual). Mueva todos los archivos almacenados en la carpeta `backup`que
creó en el directorio de conexión al directorio de trabajo. Borre, sin cambiar
el directorio de trabajo, el mencionado directorio `backup`.

		rm thehobbit.bak
		rm -r part*
		mv ~/backup/* .
		rmdir ~/backup


21. Obtenga un archivo llamado "bigger.txt" que contenga la lista de los 8
capítulos de mayor tamaño del directorio en formato largo.

		ls -lS Chapter* | head -8 > bigger.txt

    
22. Obtenga un archivo llamado "smaller.txt" que contenga la lista de los 4
capítulos de menor tamaño del directorio en formato normal, ordenados por
número de capítulo. No utilice el modificador `-r` de `ls` para esta tarea.

		ls -S Chapter* | tail -4 | sort > smaller.txt


23. El programa `uniq` sirve para eliminar lineas duplicadas (siempre que sean
consecutivas), y puede emplearse como filtro. Consulte la página del manual
para más información. Sabiendo esto, elabore un comando empleando filtros que
obtenga en cuántos de los 19 capítulos aparece la palabra "Bilbo".

		grep -l "Bilbo" Chapter* | uniq | wc -l
		12
