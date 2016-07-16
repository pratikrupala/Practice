#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void combine(int *org, int *res, int l, int m, int r)
{
	int i = 0;
	int middle = m;
	int iter = ((r - l) + 1);

	for (i = l; i <= iter; i++) {
		if (((!r) || ((l) && (org[l] < org[m]))) && (l < middle)) {
			res[i] = org[l];
			l++;
		} else if ((r) && (m < r)) {
			res[i] = org[m];
			m++;
		} else {
			printf("**ERROR**: Invalid case.\n");
		}
	}
}

void merge_sort(int *arr, int *res, int left, int right)
{
	int middle = -1;

	if ((right - left) > 0) {
		middle = ((right - left) / 2) + left;
		merge_sort(arr, res, left, middle);
		merge_sort(arr, res, middle + 1, right);
		combine(arr, res, left, (middle + 1), right);
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
		printf("**ERROR**: Failedto allocate  memory for array.\n");
		ret = -ENOMEM;
	}
	memset(input, 0, (sizeof(int) * len));

	printf("\nEnter array values:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	merge_sort(input, output, 0, (len - 1));

	printf("\nSorted array:-\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, output[i]);
	}
	printf("\n");

exit:
	return ret;
}
