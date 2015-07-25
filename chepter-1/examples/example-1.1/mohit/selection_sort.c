#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define FAILED 1
#define SUCESS 0
int sort_arr(int arr[]);
void swap(int *x, int *y);

int main()
{
	int status = FAILED;
	int arr[MAX_SIZE];
	int i;
	memset(arr, '\0', MAX_SIZE);
	printf("Unsorted Array\n");
	for (i=0; i < MAX_SIZE; i++) {
		arr[i] = rand() % 1000;
		printf("%d\t", arr[i]);
	}
	printf("\n");
	status = sort_arr(arr);
	printf("Sorted Array\n");
	for (i=0; i < MAX_SIZE ; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return status;
}

int sort_arr(int arr[MAX_SIZE])
{
	int i,j,k,min;
	for (i = 0; i < (MAX_SIZE - 1); i++) {
		j = i + 1;
		min = i;
		for (j; j < MAX_SIZE; j++) {
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
