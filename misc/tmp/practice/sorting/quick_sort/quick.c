#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void quick_sort(int *arr, int left, int right)
{
	int pivot = 0;
	int down = left;
	int up = right;
	int tmp = 0;
	static int anchor = 0;
	int i = 0;

	anchor++;
//	printf("ANCHOR(%d): ONE: left = %d, right = %d\n", anchor, left, right);
//	for (i = left; i < (right - left + 1); i++)
//        	printf("ANCHOR(%d): TWO: Arr[%d]: %d\n", anchor, i, arr[i]);

	printf("\n");
	if (left != right) {
		pivot = arr[left];
//		printf("ANCHOR(%d): THREE: pivot = %d\n", anchor, pivot);
		while (down < up) {
//	                for (i = left; i < (right - left + 1); i++)
//        	                printf("ANCHOR(%d): SPECIAL: Arr[%d]: %d\n", anchor, i, arr[i]);
//			do { down++;} while((pivot > arr[down]) && (down < right));
			while((pivot >= arr[down]) && (down < right))
				down++;
//			printf("ANCHOR(%d): FOUR: down = %d\n", anchor, down);
//			do { up--;} while((pivot < arr[up]) && (up > left));
			while((pivot <= arr[up]) && (up > left))
				up--;
//			printf("ANCHOR(%d): FIVE: up = %d\n", anchor, up);
			if (down < up) 
				SWAP(arr[down], arr[up], tmp);
			else
				break;
		}
		SWAP(arr[left], arr[up], tmp);
//		for (i = left; i < (right - left + 1); i++)
//        		printf("ANCHOR(%d): SIX: Arr[%d]: %d\n", anchor, i, arr[i]);
			if (up > left)
				quick_sort(arr, left, up - 1);
			if (up < right)
				quick_sort(arr, up + 1, right);
	}
}

int main(void)
{
	int *input = NULL;
	int len = -1;
	int i = 0;

	printf("Enter the length of the array to be sorted:");
	scanf("%d", &len);
	if (len <= 0) {
		printf("Invalid length.\n");
		exit(EXIT_FAILURE);
	}

	input = malloc(sizeof(int) * len);
	if (!input) {
		printf("Failed to allocate memory for array.\n");
		exit(EXIT_FAILURE);
	}
	memset(input, 0, (sizeof(int) * len));

	printf("\nEnter your input for array elements:\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: ", i);
		scanf("%d", &(input[i]));
	}

	quick_sort(input, 0, len - 1);
//	quick_sort(input, 0, len - 1, len);

	printf("\nYour array:\n");
	for (i = 0; i < len; i++) {
		printf("Arr[%d]: %d\n", i, input[i]);
	}
	printf("\n");

	return 0;
}
