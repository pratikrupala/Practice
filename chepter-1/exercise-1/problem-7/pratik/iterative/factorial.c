#include <stdio.h>

void factorial(int n)
{
	int i, fact = 1;

	if(n < 1)
		fact = n;
	else {
		for(i = 1; i <= n; i++) {
			fact *= i;
		}
	}
	printf("Factorial of %d: %d\n", n, fact);
}

int main(void)
{
	int x;

	printf("Enter a number:\n");
	scanf("%d", &x);

	factorial(x);

	return 0;
}
