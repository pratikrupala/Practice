#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_array(int *arr, int *result, int first, int last)
{
        int i = 0;

        for (i = first; i <= last; i++) {
                arr[i] = result[i];
        }
}

void combine(int *arr, int *res, int first, int middle, int last)
{
	int i,j;
	int a = first;
	int b = middle + 1;

	printf("Entered into combine function\n");
	for (i = first; i <= last; i++) {
		if ((b > last) || ((arr[a] < arr[b]) && (a <= middle))) {
			j = a;
			a++;
		} else if (b <= last) {
			j = b;
			b++;
		}
		res[i] = arr[j];
	}
}

void merge_sort(int *arr, int *res, int start, int end)
{
	int middle = 0;

//	printf("Entered into the merge  function.\n");
	if (start != end) {
		middle = ((end - start)/2) + start;
		merge_sort(arr, res, start, middle);
		merge_sort(arr, res, (middle + 1), end);
		combine(arr, res, start, middle, end);
		copy_array(arr, res, start, end);
	}
}

int main(void)
{
	int len = -1;
	int *inp = NULL;
	int *result = NULL;
	int i = 0;

	printf("Enter the length of the array: ");
	scanf("%d", &len);
	if (len < 1) {
		printf("Invalid length of the array.\n");
		exit(EXIT_FAILURE);
	}

	inp = malloc(len * sizeof(int));
	if (!inp) {
		printf("Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nYour input:");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(inp[i]));
	}

	result = malloc(len * sizeof(int));
        if (!inp) {
                printf("Failed to allocate memory for array.\n");
                exit(EXIT_FAILURE);
        }
	memset(result, 0, sizeof(len * sizeof(int)));

	merge_sort(inp, result, 0, (len - 1));

	printf("\nResult:");
	for (i = 0; i < len; i++) {
                printf("Arr[%d]: %d\n", i, result[i]);
        }
	printf("\n");


	return 0;
}
