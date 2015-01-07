/*
 *Calculation of binomial coefficient full list using the
 *iterative method. 
 * */

#include <stdio.h>

int main()
{
	int n,k;
	printf("Input the power of an binomial\n");
	scanf("%d",&n);
	printf("Coefficients of binomial for power %d\n", n);
	binomial_coeff(n);
	printf("\n");
	return 0;
}

binomial_coeff(int n)
{
	int k, coefficient;
	for (k = 0; k <= n; k++) {
		coefficient = fact(n)/(fact(k) * fact(n-k));
		printf("%d\t", coefficient);
	}
}

fact(int num)
{
	int i, factorial=1;
	for (i = num; i > 0; i--) {
		factorial = factorial * i;
	}
	return factorial;
}
