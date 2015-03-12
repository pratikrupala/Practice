#include <stdio.h>
#include <stdlib.h>

int **mkarray(int row)
{
	int i;
	int **x;

	if((x = malloc(row * sizeof(*x))) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < row; i++) {
		if ((*(x + i) = calloc(row, sizeof(int))) == NULL) {
			fprintf(stderr, "Failed to allocate memory.\n");
                	exit(EXIT_FAILURE);
		}
	}
	
	return x;
}

void mult(int **x, int **y, int **z, int row)
{
	int i, j, k;

	for (i = 0; i < row; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < row; k++)
				*(*(z + i) + j) += (*(*(x + i) + k)) * (*(*(y + k) + j));
		}
	}
}

void print(int **x, int row)
{
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < row; j++)
			printf("%d\t", *(*(x + i) + j));
		printf("\n");
	}
}

void scan(int **x, int row, char c)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < row; j++) {
			printf("Enter the value for matrix %c at row %d and column %d:", c, i, j);
			scanf("%d", (*(x + i) + j));
		}
	}
}

int main(void)
{
	int **a, **b, **d;
	int r = 0;

	printf("Enter the number of row:");
	scanf("%d", &r);
	if (r <= 0 ) {
		printf("Invalid value of row.\n");
		exit(EXIT_FAILURE);
	}

	a = mkarray(r);
	b = mkarray(r);

	scan(a, r, 'A');
	scan(b, r, 'B');

	printf("Matrix A:\n");
	print(a, r);

	printf("Matrix B:\n");
	print(b, r);

	d = mkarray(r);

	mult(a, b, d, r);	

	printf("Matrix D:\n");
	print(d, r);

	return 0;
}
