#include <stdio.h>
#include <stdlib.h>

int **mkmatrix(int r)
{
	int i;
	int **x;

	if ((x = malloc(r * sizeof(*x))) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < r; i++) {
		*(x + i) = calloc(r, sizeof(int));
	}

	return x;
}

void print(int **x, int r)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < r; j++)
			printf("%d\t", *(*(x + i) + j));
		printf("\n");
	}
}

void swap(int *a, int *b)
{
	int tmp = 0;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void transpose(int **x, int r)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = (i + 1); j < r; j++)
			swap((*(x + i) + j), (*(x + j) + i));
	}
}

void scan(int **x, int r)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < r; j++)	{
			printf("Enter value at row %d and column %d:", i, ((i * r) + j));
			scanf("%d", (*(x + i) + j));
		}
	}
}

int main(void)
{
	int **a;
	int row = 0;

	printf("Please enter the size of matrix:");
	scanf("%d", &row);
	if(row <= 0) {
		fprintf(stderr, "Invalid value of row.\n");
		exit(EXIT_FAILURE);
	}

	a = mkmatrix(row);
	scan(a, row);

	transpose(a, row);

	print(a, row);

	return 0;
}
