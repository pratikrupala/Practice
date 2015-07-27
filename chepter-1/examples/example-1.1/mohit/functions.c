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
}
