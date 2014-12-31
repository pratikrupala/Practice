/*
 *Horner's Rule Implemantaion using
 *Iterative and recursive Method
 * */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int coff, x, i, sum=0;
	int *arr_coff;
	printf("Input the value of variable \"x\"\n");
	scanf("%d", &x);
	printf("Input the number of coefficient\n");
	scanf("%d", &coff);
	arr_coff = (int *) malloc(sizeof(int) * coff);
	if (arr_coff == NULL) {
		printf("Error in Dynamic Allocation of memory\n");
		return -1;
	}
	for (i = 0; i <= coff; i++) {
		printf("Input the coefficient value at index %d\n", i);
		scanf("%d", (arr_coff + i));
	}
	horner_iterative(arr_coff, x, coff);
	sum = horner_recursive(arr_coff, x, coff, 0);
	printf("Output of polynomial using horner rule is (Recursive) = %d\n", sum);
	return 0;
}

horner_iterative(int *arr_coff, int x, int coff)
{
	int i, sum = *(arr_coff + coff);
	for (i = coff; i > 0; i--)
	{
		sum = (sum * x) + *(arr_coff + (i-1));
	}
	printf("Output of polynomial using horner rule is (iterative) = %d\n", sum);
}
int horner_recursive(int *arr_coff, int x, int coff, int i)
{
	if (i == coff) {
		return *(arr_coff + i );
	}
	else {
		return (*(arr_coff + i) + (x *(horner_recursive(arr_coff, x, coff, i+1))));
	}
}
