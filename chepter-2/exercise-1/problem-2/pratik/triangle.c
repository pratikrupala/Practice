#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, n = 0;
	int **arr;
	int total = 0;

	printf("Enter the number of rows in array:");
	scanf("%d", &n);

	arr = malloc(n * sizeof(*arr));

	for (i = 0; i < n; i++) {
		*(arr + i) = calloc(i, sizeof(int));
	}

	for (i = 0; i < n; i++)
		total += i;

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			printf("Enter value at row %d and column %d:", i, j);
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
                for (j = 0; j <= i; j++)
                        printf("%d\t", arr[i][j]);
		printf("\n");
        }

	return 0;
}
