/*
 *Calculation of binomial coefficient full list using the
 *iterative method. 
 * */

#include <stdio.h>

int main()
{
	int n,k,coeff_num;
	printf("Input the power of an binomial\n");
	scanf("%d",&n);
	printf("Input the coefficient number\n");
	scanf("%d",&coeff_num);
	printf("Coefficients of binomial for power %d\n", n);
	binomial_coeff(n, coeff_num);
	printf("\n");
	return 0;
}

binomial_coeff(int n, int coeff_num)
{

	printf("Power = %d\tCoefficient = %d\n ", n, fact(n)/(fact(coeff_num) * fact(n-coeff_num)));
}

fact(int num)
{
	int i, factorial=1;
	for (i = num; i > 0; i--) {
		factorial = factorial * i;
	}
	return factorial;
}
