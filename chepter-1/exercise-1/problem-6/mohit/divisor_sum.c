/*
 *Statement: Given n, a positive interger, determine
 *if n is the sum of its divisor, n is the sum of all t
 *where 1<= t <n
 * */

#include <stdio.h>

int main()
{
	int n, i, sum=0;
	printf("Input the number\n");
	scanf("%d", &n);
	for(i=1; i < n; i++ ) {
		if (0 == (n%i)) {
			sum = sum + i;	
		}
	}
	printf("Number = %d\n", n);
	if (n == sum) {
		printf("Input number divisor sum is equal to the number\n");
	}
	else
		printf("Input number divisor sum is not equal to the number\n");
	return 0;
}
