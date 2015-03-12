#include <stdio.h>
#include <stdlib.h>

int **mkarray(int row, int col)
{
	int i;
	int **x;

	if((x = malloc(row * sizeof(*x))) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < row; i++) {
		if ((*(x + i) = calloc(col, sizeof(int))) == NULL) {
			fprintf(stderr, "Failed to allocate memory.\n");
                	exit(EXIT_FAILURE);
		}
	}
	
	return x;
}

void add(int **x, int **y, int **z, int row, int col)
{
	int i, j;

	for (i =0; i < row; i++) {
		for (j = 0; j < col; j++)
			*(*(z + i) + j) = *(*(x + i) + j) + *(*(y + i) + j);
	}
}

void print(int **x, int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%d\t", *(*(x + i) + j));
		printf("\n");
	}
}

int main(void)
{
	int i, j;
	int **a, **b, **d;
	int r = 0, c = 0;

	printf("Enter the number of row:");
	scanf("%d", &r);
	if (r <= 0 ) {
		printf("Invalid value of row.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the number of column:");
	scanf("%d", &c);
	if (c <= 0) {
		printf("Invalid value of column.\n");
		exit(EXIT_FAILURE);
	}

	a = mkarray(r, c);
	b = mkarray(r, c);

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("Enter the value for matrix A at row %d and column %d:", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("Enter the value for matrix B at row %d and column %d:", i, j);
			scanf("%d", &b[i][j]);
		}
	}

	printf("Matrix A:\n");
	print(a, r, c);

	printf("Matrix B:\n");
	print(b, r, c);

	d = mkarray(r, c);

	add(a, b, d, r, c);	

	printf("Matrix C:\n");
	print(d, r, c);

	return 0;
}
