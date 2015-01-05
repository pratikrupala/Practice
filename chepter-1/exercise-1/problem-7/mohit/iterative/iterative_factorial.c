/*
 *Compute factorial of a number using iterative method
 *
 * */

#include <stdio.h>

int main()
{
	int n, i;
	long long int sum = 1;
	printf("Input a number to compute the factorial\n");
	scanf("%d", &n);
	if (n <= 1) {
		printf("Input No = %d\tFactorial(%d) = 1\n", n, n);
	}
	else {
		for(i = n; i > 1; i--) {
			sum = sum * i;
		}
		printf("Input No = %d\tFactorial(%d!) = %lld\n", n, n, sum);
	}
	return 0;
}
