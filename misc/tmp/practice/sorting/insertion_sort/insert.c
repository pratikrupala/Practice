#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void insertion_sort(int *arr, int n)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	int val = 0;
//	int tmp = 0;

/*
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1])
				SWAP(arr[j], arr[j - 1], tmp);
		}
	}
*/

	for (i = 0; i < n - 1; i++) {
		val = arr[i + 1];
		for (j = i + 1; j > 0; j--) {
			if (val < arr[j - 1]) {
				arr[j] = arr[j - 1];
				pos = j - 1;
			}
		}
		arr[pos] = val;
	}
}

int main(void)
{
	int *input = NULL;
	int len = -1;
	int i = 0;

	printf("Enter the length of the array:");
	scanf("%d", &len);
	if (len <= 0) {
		printf("Invalid length of the array.\n");
		exit(EXIT_FAILURE);
	}

	input = malloc(sizeof(int) * len);
	if (!input) {
		printf("Failed to allocate memory for array to be sorted.\n");
		exit(EXIT_FAILURE);
	}
	memset(input, 0, (sizeof(int) * len));

	printf("\nEnter array element values:\n");
	for (i = 0; i < len; i++) {
		printf("Array[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	insertion_sort(input, len);

	printf("\n");
	printf("Sorted array:\n");
	for (i = 0; i < len; i++) {
		printf("Array[%d]: %d", i, input[i]);
		printf("\n");
	}

	return 0;
}
