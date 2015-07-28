#include "functions.h"
#include <stdio.h>

int sort_arr(int arr[], int n)
{
	int i,j,k,min;
	for (i = 0; i < (n - 1); i++) {
		j = i + 1;
		min = i;
		for (j; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
	printf("Sorted Array\n");
	for (i=0; i < n; i++) {
        	printf("%d\t", arr[i]);
	}
	printf("\n");
	return SUCESS;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void genrate_rand_num(int arr[], int n)
{
	int i;
	printf("Unsorted Array\n");
	for (i=0; i < n; i++) {
        	arr[i] = rand() % 100;
        	printf("%d\t", arr[i]);
	}
	printf("\n");
}

int binary_search_iterative(int arr[], int n, int num)
{
	int index = -1; 
	int right, left, mid;
	left = 0;
	right = n-1;
	while ((right >= 0) && (left <= n-1) ) {
		mid = (left + right)/2;
		if (num == arr[mid]) {
			index = mid;
			break;
		} else {
			if (num < arr[mid]) {
				right = mid-1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return index;;
}

int binary_search_recursive(int arr[], int n, int num, int left, int right)
{
	int mid;
	int result, ret_val = -1;

	mid = (left + right)/2;
	if (right >=0 && left <= (n-1)) {
		result = COMPARE(num, arr[mid]);
		switch(result) {
			case 1:
				ret_val = binary_search_recursive(arr, n, num, mid+1, right);
				break;
			case 0:
				ret_val = mid;
				break;
			case -1:
				ret_val = binary_search_recursive(arr, n, num, mid, mid-1);	
				break;
		}
	}
	return ret_val;	
}

void permutaion(char arr[], int a, int n)
{
	char temp;
	int i,j;	
	if (a == n) {
		for (i = 0; i<=n; i++) {
			printf("%c",arr[i]);
		}
		printf("\t");
	}
	
	for (j=a; j<=n; j++) {
		SWAP(arr[a], arr[j], temp);
		permutaion(arr, a+1, n);
		SWAP(arr[a], arr[j], temp);
	}
}
