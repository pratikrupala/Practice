#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_array(int *arr, int *result, int first, int last)
{
	int i = 0;

	for (i = first; i <= last; i++) {
		arr[i] = result[i];
	}
}

void combine(int *arr, int *result, int first, int middle, int last)
{
	int i = 0;
	int j = 0;
	int a = first;
	int b = middle + 1;

	for (i = first; i <= last; i++) {
		if ((b > last) || ((a <= middle) && (arr[a] < arr[b]))) {
			j = a;
			a++;
		} else if ((b <= last)) {
			j = b;
			b++;
		}
		result[i] = arr[j];
	}
}

void merge_sort(int *arr, int *result, int first, int last)
{
	int middle = 0;

	if (first != last) {
		middle = ((last - first)/2) + first;
		merge_sort(arr, result, first, middle);
		merge_sort(arr, result, middle + 1, last);
		combine(arr, result, first, middle, last);
		copy_array(arr, result, first, last);
	}
}

int main(void)
{
	int ret = 0;
	int *input = NULL;
	int *sorted = NULL;
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

	sorted = malloc(sizeof(int) * len);
	if (!sorted) {
		printf("**ERROR**: Failed to allocate memory for sorted"
			" array.\n");
		exit(EXIT_FAILURE);
	}
	memset(sorted, 0, (sizeof(int) * len));

	printf("Enter array elements: \n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	merge_sort(input, sorted, 0, len - 1);

	printf("\nSorted array:\n");
	for (i = 0; i < len; i++)
		printf("Arr[%d]: %d\n", i, sorted[i]);
	printf("\n");

	return ret;
}
