#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void selection_sort(int *arr, int n)
{
	int i = 0;
	int j = 0;
	int min = -1;
	int tmp = 0;

	for (i = 0; i < (n - 1); i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
				SWAP(arr[min], arr[j], tmp);
		}
	}
}

int main(void)
{
	int ret = 0;
	int *input = NULL;
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
		printf("**ERROR**: Failedto allocate  memory for array.\n");
		ret = -ENOMEM;
	}
	memset(input, 0, (sizeof(int) * len));

	printf("\nEnter array values:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	selection_sort(input, len);

	printf("\nSorted array:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, input[i]);
	}
	printf("\n");

exit:
	return ret;
}
