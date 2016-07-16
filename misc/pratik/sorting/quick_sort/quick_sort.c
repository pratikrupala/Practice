#include <stdio.h>
#include <stdlib.h>

inline void swap(int *a, int *b, int *t)
{
	*t = *a;
	*a = *b;
	*b = *t;
}

void quick_sort(int *arr, int left, int right)
{
	int i = left;
	int j = right + 1;
	int pivot = left;
	int tmp = 0;

	if (left < right) {
		do {
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			if (i < j) swap(&(arr[i]), &(arr[j]), &tmp);
		} while (i < j);
		swap(&(arr[j]), &(arr[left]), &tmp);
		quick_sort(arr, left, j);
		quick_sort(arr, j + 1, right);
	}
}

int main(void)
{
	int i = 0;
	int len = -1;
	int *a = NULL;

	printf("Enter the length of the array: ");	
	scanf("%d", &len);
	
	if (len < 1) {
		printf("Invalid length.\n");
		exit(EXIT_FAILURE);
	}

	if ((a = malloc(len)) == NULL) {
		printf("Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++) {
		printf("Enter the value for location %d: ", (i + 1));
		scanf("%d", &(a[i]));
	}

	quick_sort(a, 0, len - 1);

	for (i = 0; i < len; i++) {
		printf("\t%d", a[i]);
	}
	printf("\n");

	return 0;
}
