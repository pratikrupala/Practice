#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) ((type) malloc(size))
#define CALLOC(type, memb, size) ((type) calloc(memb, size))
#define SWAP(temp, x, y) ((temp = x), (x = y), (y = temp))

int main()
{
	int **a, row, i, j, k=0;
	printf("Input the size of Symmetrical matrix");
	scanf("%d", &row);
	a = MALLOC(int **, row * sizeof(int));
	for(i = 0; i < row; i++){
		*(a + i) = CALLOC(int *, row, sizeof(int));
	}
	for(i = 0; i < row; i++){
		for(j = 0; j < row; j++){
			*(*(a + i) + j) = ++k;
		}
	}
	print_arr(a, row);
	transpose(a, row);
	return 0;
}

transpose(int **a, int row)	
{
	int i, j, type; 
	for(i = 0; i < row; i++){
		j = i;
		for(;j < row; j++){
			SWAP(type, *(*(a + i) + j), *(*(a + j) + i));
		}
	}
	printf("Transpose:\n");
	print_arr(a, row);
	return 0;
}

print_arr(int **a, int row)
{
	int i, j;
	for (i = 0; i < row; i++){
		for(j = 0; j < row; j++){
			printf("%d\t", *(*(a + i) + j));
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
