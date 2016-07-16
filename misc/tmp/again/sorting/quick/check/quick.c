#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void quick_sort(int *arr, int start, int end)
{
	int pivot = start;
	int left = start;
	int right = end;
	int tmp;

	if (start != end) {
		while (left < right) {
			while ((left < end) && (arr[left] <= arr[pivot])) {
				left++;
			}
			while ((right > start) && (arr[right] >= arr[pivot])) {
				right--;
			}
			if (left < right)
				SWAP(arr[left], arr[right], tmp);
			else
				break;
		}
		SWAP(arr[pivot], arr[right], tmp);
		if (right > start)
			quick_sort(arr, start, (right - 1));
		if (right < end)
			quick_sort(arr, (right + 1), end);
	}
}

int main(void)
{
	int len = -1;
	int *inp = NULL;
	int i = 0;

	printf("Enter the length of the array to be sorted: ");
	scanf("%d", &len);
	if (len < 0) {
		fprintf(stderr, "Invalid length of the array.\n");
		exit(EXIT_FAILURE);
	}

	inp = malloc(len * sizeof(int));
	if (!inp) {
		fprintf(stderr, "Failed to allocate  memory.\n");
		exit(EXIT_FAILURE);
	}

	printf("\n");
	for (i = 0; i < len; i++) {
		printf("Enter value of Arr[%d]: ", i);
		scanf("%d", &(inp[i]));
	}

	quick_sort(inp, 0, (len - 1));

	printf("\nSorted array:");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, inp[i]);
	}

	return 0;
}
