#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x, coff,i,sum;
	int *arr_coff;
	printf("Input the value of variable 'x'\n");
	scanf("%d", &x);
	printf("Input the number of coefficient\n");
	scanf("%d", &coff);
	
	arr_coff = (int *) malloc(sizeof(int) * coff);
	if (arr_coff ==NULL) {
		printf("System is out of memory\n");
		return -1;
	}
	printf("Input the coefficient\n");
	for(i=0; i<coff;i++) {
		scanf("%d", (arr_coff+i));
	}
	for(i=0; i<coff;i++) {
		printf("%d\t", *(arr_coff+i));
	}
	printf("\n");
	sum = horner_solution_iterative(arr_coff, x, coff-1);
	printf("Iterative Result = %d\n",sum);
	sum = 0;
	sum = horner_solution_recursive(arr_coff, x, 0, coff-1);
	printf("Recurcive Result = %d\n",sum);
	return 0;
}

int horner_solution_iterative(int *arr_coff, int x, int coff)
{
	int sum = *(arr_coff+coff);
	int i;
	for (i = (coff-1); i>=0; i--) {
		sum = *(arr_coff+i) + (x * sum);
	}
	return sum;
}

int horner_solution_recursive(int *arr_coff, int x, int y, int coff)
{
	if (y < coff) {
		return (*(arr_coff+y) + (x * (horner_solution_recursive(arr_coff, x, y+1, coff))));
	} else {
		return (*(arr_coff+coff));
	}
		
}
