#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int tmp = -1;

	for (i = 1; i < n; i++) {
		tmp = a[i];
		j = i;
		while (j && a[j - 1] > tmp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}

}

int main(void)
{
	int len = -1;
	int *arr = NULL;
	int i = 0;

	printf("Enter the length of the array to be sorted: ");
	scanf("%d", &len);

	arr = malloc(len);
	if (!arr) {
		printf("Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++) {
		printf("Enter the value of array element at position %d: ", (i + 1));
		scanf("%d", &(arr[i]));
	}

	insertion_sort(arr, len);

	for (i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return 0;
}
