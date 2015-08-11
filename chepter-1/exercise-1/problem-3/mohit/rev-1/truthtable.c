#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x) ((x == 1)? (x=0):(x=1))

int main()
{
	int n;
	int *arr;
	printf("Input the Number of Boolean Variables\n");
	scanf("%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	if (arr == NULL) {
		printf("Allocation of Memory Failed\n");
		return -1;
	}
	memset(arr, 0, n);	
	truth_table_gen(arr, 0, n-1, n-1);	
	printf("\n");
	return 0;
}

int truth_table_gen(int *arr, int i, int n, int a)
{
	int j,k;
	if (n == i) {
		for (j=0; j <=a; j++) {
			printf("%d", *(arr+j));
		}
		printf("\t");
	}
	for (k=0; k<=n; k++) {
	}
	else {
		for (k=0; k<=n; k++) {
			printf("n-1 = %d\n", n-1);
			truth_table_gen(arr, 0, n-1,a);
			printf("Swaping n=%d, *(arr+n)=%d", n, *(arr+n));
			SWAP(*(arr+n));
			printf("Calling after Swap n = %d\n", n);
			truth_table_gen(arr, 0, n,a);
		}
	}
	return 0;
}
