#include <stdio.h>
#include <stdlib.h>

void printarr(int *list, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		printf("Index: %d and value: %d\n", i, *(list+i));
	}
}

int main(void)
{
	int i, n = 0;
	int *input;

	printf("Enter the size of size of array:");
	scanf("%d", &n);

	input = malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		*(input+i) = i;

	printarr(input, n);

	exit(EXIT_SUCCESS);
}

