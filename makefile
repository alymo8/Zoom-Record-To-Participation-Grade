
labapp: labapp.o zoomrecs.o
	gcc -o labapp labapp.o zoomrecs.o

labapp.o: labapp.c zoomrec.h
	gcc -c labapp.c

zoomrecs.o: zoomrecs.c zoomrec.h
	gcc -c zoomrecs.c
