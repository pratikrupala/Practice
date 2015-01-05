/*
 *Compute the factorial of n using recursive method
 *
 * */

#include <stdio.h>

int main()
{
	int n;
	long long int factorial;
	printf("Input the Number for factorial Calculation\n");
	scanf("%d", &n);
	factorial = fact(n);
	printf("Factorial(%d!) = %lld\n",n ,factorial);
	return 0;
}

fact(int n)
{
	if (n > 0) {
		return (n * fact(n-1));
	}
	else
		return 1;
}
