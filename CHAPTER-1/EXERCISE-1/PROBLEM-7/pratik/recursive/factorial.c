#include <stdio.h>

int factorial(int n)
{
	int i;

	if(n < 1)
		return 1;
	else {
		return n * factorial(n-1);
	}
}

int main(void)
{
	int x, fact = 0;

	printf("Enter a number:\n");
	scanf("%d", &x);

	if(x < 1)
		fact = x;
	else
		fact = factorial(x);

	printf("Factorial of %d: %d\n", x, fact);

	return 0;
}
