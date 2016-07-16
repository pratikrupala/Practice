#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void combine(int *org, int *res, int l, int m, int r)
{
	int i = 0;
	int left = m - l + 1;
	int right = r - m;
	int middle = m + 1;
	int total = (r - l) + 1;

	for (i = left; i <= total; i++) {
		if ((!right) || ((l) && (org[l] < org[middle]))) {
			res[i] = org[l];
			l++;
		} else if ((r) && ((!l) && (org[middle] < org[l]))) {
			res[i] = org[middle];
			middle++;
		} else {
			printf("**ERROR**: Invalid case.\n");
		}
	}
}

void merge(int *arr, int *res, int left, int right)
{
	int middle = 0;

	if (left != right) {
		middle = ((right - left) / 2) + left;
		merge(arr, res, left, middle);
		merge(arr, res, middle + 1, right);
		combine(arr, res, left, middle, right);
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
		printf("**ERROR**: Failed to allocate memory for array.\n");
		ret = -ENOMEM;
	}
	memset(input, 0, (sizeof(int) * len));

	printf("\nEnter array values:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	output = malloc((sizeof(int) * len));
	if (!output) {
		printf("**ERROR**: Failed to allocate memory for"
			" output array.\n");
		ret = -ENOMEM;
	}
	memset(output, 0, (sizeof(int) * len));

	merge(input, output, 0, (len - 1));

	printf("\nSorted array:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, input[i]);
	}
	printf("\n");

exit:
	return ret;
}
