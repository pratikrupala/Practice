#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) ((type)malloc(size))
#define CALLOC(type, memb, size) ((type) calloc(memb, size))

int main()
{
	int row, column, i, j, k=0;
	int **a, **b;
	printf("Input the number of rows\n");
	scanf("%d", &row);
	printf("Input the number of column\n");
	scanf("%d", &column);
	a = MALLOC(int **, row * sizeof(int *));
	b = MALLOC(int **, column * sizeof(int *));
	for (i = 0; i < row; i++){
		*(a + i) = CALLOC(int *, column, sizeof(int));
	}
	for (i = 0; i < column; i++){
		*(b + i) = CALLOC(int *, row, sizeof(int));
	}
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			*(*(a + i) + j) = ++k;
		}
	}
	print_arr(a, row, column);
	transpose(a, b, row, column);
	return 0;
}

transpose(int **a, int **b, int row, int column)
{
	int i, j;
	for(i = 0; i < row; i++ ){
		for (j = 0; j < column; j++){
			*(*(b + j) + i) = *(*(a + i) + j);
		}
	}
	print_arr(b, column, row);
	return 0;
}

print_arr(int **a, int row, int column)
{
	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d\t", *(*(a + i) + j));
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
