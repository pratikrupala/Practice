/*
 *Printing the binary combinations for number of boolen variables
 *
 * */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i=0, j=0;
	int *arr;
	printf("Inpue the number of boolean variables\n");
	scanf("%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	for(j; j < n; j++) {
		arr[j] = 0;
	}
	truth_table(arr, n-1, i); 
	return 0;
}

truth_table(int *arr, int n, int i)
{
	int j, k=1, l;
	if (i == n) {
		while(k <= 2) {
			for (l=0; l <= n; l++) {
				printf("%d", arr[l]);
			}
			printf("\n");
			arr[n] = 1;
			k++;
		}
	}
	else {
		for (j=0; j < 2; j++) {
			truth_table(arr, n, i+1);
			arr[i] = 1;
			for (l=i+1; l <=n; l++) {
				arr[l] = 0;
			}
		}
	}
}
