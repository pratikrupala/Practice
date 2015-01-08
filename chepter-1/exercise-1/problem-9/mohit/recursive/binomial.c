/*
 *Calculation of binomial coefficient full list using the
 *recursive method. 
 * */

#include <stdio.h>

int main()
{
	int n,k,i=0;
	printf("Input the power of an binomial\n");
	scanf("%d",&n);
	printf("Coefficients of binomial for power %d\n", n);
	binomial_coeff(n, i);
	printf("\n");
	return 0;
}

binomial_coeff(int n, int i)
{
	int coefficient;
	if (i<=n) {
		binomial_coeff(n, i+1);
		coefficient = fact(n)/(fact(i) * fact(n-i));
		printf("%d\t", coefficient);
	}
	else
		return;
}

fact(int num)
{
	int i, factorial=1;
	for (i = num; i > 0; i--) {
		factorial = factorial * i;
	}
	return factorial;
}
