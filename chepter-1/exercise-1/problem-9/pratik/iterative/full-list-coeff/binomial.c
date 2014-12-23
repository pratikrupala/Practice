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

int binomial_coeff(int n)
{
	int i = 0, j = 0;

	for(i = 0; i < n; i++) {
		for(j = 0; j < (n - i -1); j++)
			printf(" ");

		for(j = 0; j <= i; j++)
			printf("%d ", (factorial(i)/(factorial(j)*factorial(i - j))));
		
		printf("\n");
	}
}

int main(void)
{
	int n = 0;

	printf("Enter the value of degree(n):");
	scanf("%d", &n);

	if(n < 1) {
		printf("Invalid value of n.\n");
		exit(EXIT_FAILURE);
	}

	binomial_coeff(n);

	return 0;
}
