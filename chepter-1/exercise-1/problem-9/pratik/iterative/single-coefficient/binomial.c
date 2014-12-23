#include <stdio.h>
#include <stdlib.h>

int factorial(int a)
{
	int i = 0, res = 1;

	for(i = a; i > 0; i--) {
		res *= i;
	}

	return res;
}

int binomial_coeff(int n, int k)
{
	return (factorial(n)/(factorial(k)*factorial(n - k)));
}

int main(void)
{
	int n = 0, k = 0, r = 0;

	printf("Enter the value of degree(n):");
	scanf("%d", &n);

	if(n < 1) {
		printf("Invalid value of n.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the value of k:");
	scanf("%d", &k);

	if(k < 0) {
		printf("Invalid value of k.\n");
		exit(EXIT_FAILURE);
	}

	r = binomial_coeff(n, k);

	printf("Binomial coefficient of given numbers is %d\n", r);

	return 0;
}
