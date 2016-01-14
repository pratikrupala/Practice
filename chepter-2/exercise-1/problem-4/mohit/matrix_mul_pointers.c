#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) ((type) malloc(size))
#define CALLOC(type, memb, size) ((type) calloc(memb, size))

int main()
{
	int **a, **b, **c, row, i, j, k = 0;
	printf("Input the size of symatrical matrix"\n);
	scanf("%d", &row);
	a = MALLOC(int **, row * sizeof(int *));
	b = MALLOC(int **, row * sizeof(int *));
	c = MALLOC(int **, row * sizeof(int *));
	for (i = 0; i < row; i++){
		*(a + i) = CALLOC(int *, row, sizeof(int));
		*(b + i) = CALLOC(int *, row, sizeof(int));
		*(c + i) = CALLOC(int *, row, sizeof(int));
	}
	for (i = 0; i < row; i++){
		for(j = 0; j < row; j++){
		*(*(a + i) + j)	= ++k;
		*(*(b + i) + j)	= ++k;
		}
	}
	mul(a, b, c, row);
	return 0;
}
mul(int **a, int **b, int **c, int row){
	int i, j, k = 0, sum = 0;
	for(i = 0; i < row; i++ ){
		sum = 0;
		for(j = 0, k = 0; j < row, k < row; j++, k++){
			sum = sum + ((*(*(a + i) + j)) * *(*(b + k) + i));
		}
		*(*(c ))
	}
}
