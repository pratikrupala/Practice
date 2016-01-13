#include <stdio.h>
#include <stdlib.h>

#define MALLOC(type, size) ((type)malloc(size))
#define CALLOC(type, memb, size) ((type) calloc(memb, size))

int main()
{
	int **twodarr, row, column, i, j;
	printf("Input the row\n");
	scanf("%d", &row);
	twodarr = MALLOC(int **, row * sizeof(int *));
	for (i = 0; i < row; i++){
		*(twodarr + i) = CALLOC(int *, (i + 1), sizeof(int));
	}
	for(i = 0; i < row; i++){
		for(j=0; j < (i + 1); j++){
			printf("%d\t",*(*(twodarr + i) + j));
		}
		printf("\n");
	}
	return 0;
}
