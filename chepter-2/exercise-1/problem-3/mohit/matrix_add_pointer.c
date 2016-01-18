#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) ((type) malloc(size))
#define CALLOC(type, memb, size) ((type) calloc(memb, size))

int main()
{
	int **a, **b, **c, row, column;
	int i, j, k=0;
	printf("Input the number of rows\n");
	scanf("%d", &row);
	printf("Input the number of column\n");
	scanf("%d", &column);
	a = MALLOC(int **, row * sizeof(int *));
	b = MALLOC(int **, row * sizeof(int *));
	c = MALLOC(int **, row * sizeof(int *));
	for (i = 0; i < row; i++){
		*(a + i) = CALLOC(int *, column, sizeof(int));
		*(b + i) = CALLOC(int *, column, sizeof(int));
		*(c + i) = CALLOC(int *, column, sizeof(int));
	}
	for (i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			*(*(a + i) + j) = ++k;
			*(*(b + i) + j) = ++k;
		}
	}
	sum(a, b, c, row, column);
	return 0;
}
sum(int **a, int **b, int **c, int row, int column){
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			*(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
		}
	}
	print2darr(a, row, column);
	print2darr(b, row, column);
	print2darr(c, row, column);
}

print2darr(int **arr, int row, int column)
{
	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}
