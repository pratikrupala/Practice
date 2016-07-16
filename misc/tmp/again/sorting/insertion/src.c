#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void insertion_sort(int *inp, int l)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	for (i = 0; i < (l - 1); i++) {
		for (j = (i + 1); j > 0; j--) {
			if (inp[j] < inp[j - 1])
				SWAP(inp[j], inp[j - 1], tmp);
		}
	}
}

int main(void)
{
	int i = 0;
	int len = -1;
	int *arr = NULL;

	printf("Enter the length of the array: ");
	scanf("%d", &len);
	if (len < 0) {
		printf("Invalid length of the array.\n");
		exit(EXIT_FAILURE);
	}

	arr = malloc(len * sizeof(int));
	if(!arr) {
		printf("Failed to allocate memory for array to be sorted.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nEnter your input.\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(arr[i]));
	}

	insertion_sort(arr, len);

	printf("\nSorted array.\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, arr[i]);
	}

	return 0;
}
