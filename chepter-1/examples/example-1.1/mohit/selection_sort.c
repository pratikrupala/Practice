#include <stdio.h>
#include <string.h>
#include "functions.h"

int main()
{
	int status = FAILED;
	int arr[MAX_SIZE];
	int i,n;
	memset(arr, '\0', MAX_SIZE);
	printf("Input the number to sort\n");
	scanf("%d", &n);
	if (n <= 1 && n >= MAX_SIZE) {
		printf("Input should be in range of 1 to 999");
		return FAILED;
	}
	printf("Unsorted Array\n");
	for (i=0; i < n; i++) {
		arr[i] = rand() % 100;
		printf("%d\t", arr[i]);
	}
	printf("\n");
	status = sort_arr(arr, n);
	printf("Sorted Array\n");
	for (i=0; i < n ; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return status;
}
