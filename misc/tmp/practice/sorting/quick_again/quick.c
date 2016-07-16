#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void quick_sort(int *arr, int first, int last)
{
	int pivot = 0;
	int tmp = 0;
	int left = first;
	int right = last;

	if (first != last) {
		pivot = arr[left];
		while (left < right) {
			while (pivot >= arr[left] && left < last)
				left++;
			while (pivot <= arr[right] && right > first)
				right--;
			if (left < right)
				SWAP(arr[left], arr[right], tmp);
			else
				break;
		}
		SWAP(arr[first], arr[right], tmp);
		if (right > first)
			quick_sort(arr, first, right - 1);
		if (right < last)
			quick_sort(arr, right + 1, last);
	}
}

int main(void)
{
	int ret = 0;
	int *input = NULL;
	int len = 0;
	int i = 0;

	printf("\nEnter the length of the array: ");
	scanf("%d", &len);
	if (len <= 0) {
		printf("**ERROR**: Invalid length of the array.\n");
		exit(EXIT_FAILURE);
	}

	input = malloc(sizeof(int) * len);
	if (!input) {
		printf("**ERROR**: Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}
	memset(input, 0, (sizeof(int) * len));

	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}
	printf("\n");

	quick_sort(input, 0, len - 1);

	printf("Sorted array:\n");
	for (i = 0; i < len; i++)
		printf("Arr[%d]: %d\n", i, input[i]);

	printf("\n");

	return ret;
}
