#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void quick_sort(int *inp, int start, int end)
{
	int tmp = 0;
	int low = start;
	int high = end;
	int pivot = 0;

	if (start != end) {
		pivot = inp[low];
		while (low < high) {
			while ((pivot >= inp[low]) && (low < end))
				low++;
			while ((pivot <= inp[high]) && (high > start))
				high--;
			if (high > low)
				SWAP(inp[low], inp[high], tmp);
			else
				break;
		}
		SWAP(inp[start], inp[high], tmp);
		if (high > start)
			quick_sort(inp, start, (high - 1));
		if (high < end)
			quick_sort(inp, (high + 1), end);
	}
}

int main(void)
{
	int i = 0;
	int len = -1;
	int *arr = NULL;

	printf("\nEnter the length of the array: ");
	scanf("%d", &len);
	if (len < 0) {
		printf("Invalid length.\n");
		exit(EXIT_FAILURE);
	}

	arr = malloc(len * sizeof(int));
	if (!arr) {
		printf("Failed to allocate memory for array to be sorted.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nEnter values to be sorted.\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(arr[i]));
	}

	quick_sort(arr, 0, (len - 1));

	printf("\nSorted array.\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, arr[i]);
	}

	return 0;
}
