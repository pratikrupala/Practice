#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int arrsum(int list[], int size)
{
	int i, mysum = 0;

	for (i = 0; i < size; i++) {
		mysum += list[i];
	}

	return mysum;
}

int main(void)
{
	int i, sum = 0;
	int input[MAX_SIZE];

	for (i = 0; i < MAX_SIZE; i++)
		input[i] = i;

	sum = arrsum(input, MAX_SIZE);
	printf("Sum of array values: %d\n", sum);

	exit(EXIT_FAILURE);
}

