#include <stdio.h>

#define MAX_DEGREE 10

int evaluate(int list[], int x, int n, int j)
{
	if(j < n) {
		return (list[j] + x * evaluate(list, x, n, j+1));
	}
	else
		return 0;
}

int main(void)
{
	int x, n, i, r = 0, j =0;
	int coef[MAX_DEGREE];

	printf("Please enter the value of variable:\n");
	scanf("%d", &x);

	printf("Please enter the value of degree:\n");
	scanf("%d", &n);

	if(n > MAX_DEGREE) {
		printf("value of degree out of range\n");
	}

	printf("Please enter %d number of coefficient:\n", n);
	for(i = 0; i < n; i++) {
		scanf("%d", &coef[i]);
	}

	coef[n] = 0;

	r = evaluate(coef, x, n, j);

	printf("Final result: %d\n", r);

	return 0;
}
