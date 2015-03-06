#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printarr(int *list, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		printf("Index: %d and value: %d\n", i, *(list+i));
	}
}

int main(void)
{
	int i;
	int input[MAX_SIZE];

	for (i = 0; i < MAX_SIZE; i++)
		input[i] = i;

	printarr(input, MAX_SIZE);

	exit(EXIT_FAILURE);
}

