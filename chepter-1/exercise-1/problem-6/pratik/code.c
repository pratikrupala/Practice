#include <stdio.h>

#define MOD(m, n) (m % n)

void compute(int n)
{
	int i, a, sum;

	for(a = 1; a <= n; a++) {
		sum = 0;
		for(i = 1; i < a; i++) {
			if((MOD(a, i)) == 0) {
				sum += i;
			}
		}

		if(sum == a)
			printf("Number is equal to sum of its divisiors: %d\n", a);
		else
			printf("Number is not equal to sum of its divisiors: %d\n", a);
	}
}

int main(void)
{
	int x = 0;

	printf("Enter the range of numbers:");
	scanf("%d", &x);

	compute(x);

	return 0;
}
