#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **x;
	int r = 0;
	int c = 0;
	int i, j, total = 0;

	printf("Enter the number of rows of two dimentional array:");
	scanf("%d", &r);

	if (r <= 0) {
		printf("Invalid value of rows.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the number of columns of two dimentional array:");
	scanf("%d", &c);

	if (c <= 0) {
		printf("Invalid value of columns.\n");
		exit(EXIT_FAILURE);
	}

	x = malloc(r * sizeof(*x));

	for (i = 0; i < c; i++)
		*(x+i) = malloc(c * sizeof(int));

	total = r * c;

	for (i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			printf("Enter the value at row %d and column %d:", i, j);
			scanf("%d", &x[i][j]);
		}
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d\t", x[i][j]);
		printf("\n");
	}

	return 0;
}
