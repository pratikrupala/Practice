#include <stdio.h>
#include <stdlib.h>

int **mkarr(int r, int c)
{
	int i;
	int **x;

	if ((x = malloc(r * sizeof(*x))) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < r; i++) {
		if ((*(x + i) = calloc(c, sizeof(int))) == NULL) {
			fprintf(stderr, "Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
	}

	return x;
}

void print(int **x, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d\t", *(*(x + i) + j));
		printf("\n");
	}

}

void scan(int **x, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("Enter value at row %d and col %d:", i , ((i * c) + j));
			scanf("%d", (*(x + i) + j));
		}
	}
}

void transpose(int **x, int **y, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			*(*(y + j) + i) = *(*(x + i) + j);
	}

}

int main(void)
{
	int **a, **b;
	int row = 0, col = 0;

	printf("Enter the value of row:");
	scanf("%d", &row);
	if (row <= 0) {
		fprintf(stderr, "Invalid value of row.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the value of column:");
        scanf("%d", &col);
        if (col <= 0) {
                fprintf(stderr, "Invalid value of col.\n");
                exit(EXIT_FAILURE);
        }

	a = mkarr(row, col);
	
	scan(a, row, col);

	b = mkarr(col, row);
	transpose(a, b, row, col);

	printf("Matrix A:\n");
	print(a, row, col);

	printf("Matrix B:\n");
	print(b, col, row);

	return 0;
}
