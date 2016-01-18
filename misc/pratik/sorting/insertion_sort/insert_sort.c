#include <stdio.h>
#include <stdlib.h>

#define swap(a, b, t) {t = a; a = b; b = t;}

void insert_sort(int *a, int n)
{
	int j = 0, k = 0, t = 0;

	for (j = 1; j < n; j++) {
		k = j;
		while (k && (*(a + k - 1) > *(a + k))) {
			swap(*(a + k - 1), *(a + k), t);
			k -= 1;
		}
	}
}

int main(void)
{
	int *arr, i = 0;
	int len = -1;

	printf("Enter the length of the array: ");
	scanf("%d", &len);

	arr = malloc(len * sizeof(int));
	if (!arr) {
		printf("Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++) {
		printf("Enter value at location %d: ", (i + 1));
		scanf("%d", (arr + i));
	}

	insert_sort(arr, len);

	printf("Sorted array: ");
	for (i = 0; i < len; i++) {
		printf("%d \t", *(arr + i));
	}
	printf("\n");

	return 0;
}
