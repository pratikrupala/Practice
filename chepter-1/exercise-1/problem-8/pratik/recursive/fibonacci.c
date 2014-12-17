#include <stdio.h>

void fibonacci(int a, int b, int n)
{
	int i;

	if(n > 0) {
		printf("%5d", (a + b));
		fibonacci(b, (a + b), n-1);
	}
}

int main(void)
{
	int n = 0;
	int x = 0;
	int y = 1;

	printf("Enter a limiting number:");
	scanf("%d", &n);

	printf("%5d%5d", x, y);

	fibonacci(x, y, n-2);

	printf("\n");

	return 0;
}
