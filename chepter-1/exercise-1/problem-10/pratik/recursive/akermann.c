#include <stdio.h>
#include <stdlib.h>

int akermann(int m, int n)
{
	if(m == 0)
		return (n + 1);

	if(m > 0 && n == 0)
		return akermann(m-1, 1);

	if(m > 0 && n > 0)
		return akermann(m-1, akermann(m, n-1));
	
	return 0;
}

int main(void)
{
	int m = 0, n = 0, r = 0;

	printf("Enter the value of m:");
	scanf("%d", &m);

	if(m < 0) {
		printf("Invalid input value of m\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the value of n:");
	scanf("%d", &n);

	if(m == 0 && n == 0) {
		printf("You have entered wrong input\n");
		exit(EXIT_FAILURE);
	}

	r = akermann(m, n);

	printf("Solution of Akermann for m: %d and n: %d is %d\n", m, n, r);

	return 0;
}
