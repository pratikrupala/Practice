#include <stdio.h>

void fibonacci(int n)
{
	int i;
	int x = 0;
	int y = 1;
	int z = 0;

	printf("%5d%5d", x, y);

	for(i = 0; i < n-2; i++) {
		z = x + y;
		x = y;
		y = z;
		printf("%5d", z);
	}
	printf("\n");
}

int main(void)
{
	int n = 0;

	printf("Enter a limiting number:");
	scanf("%d", &n);

	fibonacci(n);

	return 0;
}
