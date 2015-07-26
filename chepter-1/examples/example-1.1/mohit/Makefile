CC = gcc

DEPS = functions.h

OBJ = functions.o selection_sort.o

SOURCE = functions.c selection_sort.c

all: selec_sort

selec_sort: $(OBJ)
	$(CC)  -o selec_sort $(OBJ)

functions.o: 
	$(CC) -c functions.c  

selection_sort.o: 
	$(CC) -c selection_sort.c

clean:
	rm -f *.o selec_sort
