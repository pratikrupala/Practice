#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void selection_sort(int *inp, int l)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int max = 0;

	for (i = 0; i < (l - 1); i++) {
		max = i;
		tmp = 0;
		for (j = i; j < l; j++) {
			if (inp[j] < inp[max])
				max = j;
		}
		SWAP(inp[i], inp[max], tmp);
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
	if (!arr) {
		printf("Failed to allocate memory for input array.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nEnter your input for the array to be sorted.\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(arr[i]));
	}

	selection_sort(arr, len);

	printf("\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, arr[i]);
	}

	return 0;
}
