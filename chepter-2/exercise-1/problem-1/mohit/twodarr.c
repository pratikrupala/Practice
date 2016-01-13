#include <stdio.h>
#include <stdlib.h>

#define CALLOC(type, nmem, size) ((type) calloc(nmem, size))
#define MALLOC(type, size) ((type) malloc(size))

int main()
{
	int **twodarr, row, column, i, j;
	printf("Input the number of rows\n");
	scanf("%d", &row);
	printf("Input the number of column\n");
	scanf("%d",&column);
	twodarr = MALLOC(int **, row * sizeof(int *)); 
	for(i = 0; i < column; i++){
		*(twodarr + i) = CALLOC(int *, column, sizeof(int));
	}
	printf("Elements are\n");
	for(i=0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%d\t", *(*(twodarr + i) + j));
		}
		printf("\n");
	}
	return 0;
}
