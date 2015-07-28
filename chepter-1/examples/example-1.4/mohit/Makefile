CC = gcc

all: permutaion 

permutaion: permutaion.o functions.o 
	$(CC) -o permutaion permutaion.o ../../example-1.1/mohit/functions.o

permutaion.o:
	$(CC) -c permutaion.c

functions.o:
	make -C ../../example-1.1/mohit/ functions.o

clean:
	rm -f *.o permutaion
	make -C ../../example-1.1/mohit/ clean
	
