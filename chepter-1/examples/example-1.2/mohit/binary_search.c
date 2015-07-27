#include <stdio.h>
#include <string.h>
#include "../../example-1.1/mohit/functions.h"

int main()
{
	int n, num, index, left, right;

	printf("Input the number to genrate a random array.\n");
	scanf("%d", &n);

	if (n <= 1 && n >= MAX_SIZE){
		printf("Please enter in a range of 2 to 999");
		return FAILED;
	}
	
	int arr[n];
	memset(arr, '\0', sizeof(arr[n]));
	
	genrate_rand_num(arr, n);
	
	sort_arr(arr, n);

	printf("Input a num to search in the array\n");
	scanf("%d", &num);
	
	left = 0, right = n;

	index = binary_search_iterative(arr, n, num);
	
	if (index == -1) {
		printf("Number not present in the array.. Good Luck Next Time\n");
	}
	else {
		printf("Iterative Search..Number = %d\tIndex = %d\n", num, index);
	}
	
	index = binary_search_recursive(arr, n, num, left, right);
	
	if (index == -1) {
		printf("Number not present in the array.. Good Luck Next Time\n");
	}
	else {
		printf("Iterative Search..Number = %d\tIndex = %d\n", num, index);
	}

	return SUCESS;
}
