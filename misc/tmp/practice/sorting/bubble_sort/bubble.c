#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void bubble_sort(int *arr, int n)
{
	int i, j, tmp;
	int swapped = 0;

	for (i = 0; i < n; i++) {
		swapped = 0;
		for (j = 1; j < n; j++) {
			if (arr[j] < arr[j - 1]) {
				SWAP(arr[j - 1], arr[j], tmp);
				swapped = 1;
			}
		}
		if (!swapped)
			return;
	}
}

int main(void)
{
	int *arr = NULL;
	int len = -1;
	int i;

	printf("Enter the length of the array:");
	scanf("%d", &len);
	if (len <= 0) {
		printf("Invalid length value.");
		return 1;
	}

	arr = malloc(len);
	if(!arr) {
		printf("Failed to allocate memory for array.");
		return 1;
	}

	printf("\n");
	printf("Enter array elements:\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(arr[i]));
	}

	bubble_sort(arr, len);

	printf("\n");
	printf("Array Elements:\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, arr[i]);
	}
	printf("\n");

	return 0;
}
