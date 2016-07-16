#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void quick_sort(int *arr, int *res, int left, int right)
{
	int pivot = left;
	int up = right;
	int down = left;
	int tmp = 0;

	if (left < right) {
		while (down < up) {
			while((arr[pivot] > arr[down]) &&
				(down < right))
				down++;
			while((arr[pivot] < arr[up]) &&
				(up > left))
				up--;
			if (down < up)
				SWAP(arr[up], arr[down], tmp);
			else
				break;
		}
		SWAP(arr[pivot], arr[up], tmp);
		quick_sort(arr, res, left, up - 1);
		quick_sort(arr, res, up + 1, right);
	}
}

int main(void)
{
	int ret = 0;
	int *input = NULL;
	int *output = NULL;
	int len = -1;
	int i = 0;

	printf("Enter the length of the array to be sorted: ");
	scanf("%d", &len);
	if (len <= 0) {
		printf("**ERROR**: Invalid length.\n");
		ret = -EINVAL;
		goto exit;
	}

	input = malloc((sizeof(int) * len));
	if (!input) {
		printf("**ERROR**: Failedto allocate memory for input"
			" array.\n");
		ret = -ENOMEM;
	}
	memset(input, 0, (sizeof(int) * len));

	output = malloc((sizeof(int) * len));
	if (!input) {
		printf("**ERROR**: Failedto allocate  memory for output"
			" array.\n");
		ret = -ENOMEM;
	}
	memset(output, 0, (sizeof(int) * len));

	printf("\nEnter array values:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	quick_sort(input, output, 0, (len - 1));

	printf("\nSorted array:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, input[i]);
	}
	printf("\n");

exit:
	return ret;
}
