#include <stdio.h>
#include <stdlib.h>

inline void swap(int *a, int *b, int *t)
{
	*t = *a;
	*a = *b;
	*b = *t;
}

void select_sort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int min = - 1;
	int tmp;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i; j < n; j++) {
			if (a[min] > a[j])
				min = j;
		}
		swap(&(a[i]), &(a[min]), &tmp);
	}
}

int main(void)
{
	int i = 0;
	int *arr = NULL;
	int len = -1;

	printf("Enter the length of the array to be sorted: ");
	scanf("%d", &len);

	arr = (int *) malloc(len);

	for (i = 0; i < len; i++) {
		printf("Enter the element value of array at position %d: ", (i + 1));
		scanf("%d", &(arr[i]));
	}

	select_sort(arr, len);

	printf("Sorted array:\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return 0;
}
