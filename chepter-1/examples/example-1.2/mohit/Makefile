CC = gcc

all: binary_search

binary_search: binary_search.o functions.o 
	$(CC) -o binary_search binary_search.o ../../example-1.1/mohit/functions.o

binary_search.o:
	$(CC) -c binary_search.c

functions.o:
	make -C ../../example-1.1/mohit/ functions.o

clean:
	rm -f *.o binary_search
	make -C ../../example-1.1/mohit/ clean
	
