/*
 *Fibonacci Series implementation by the recursive method
 *f(i)=f(i-1) + f(i-2)		where f(0)=0 f(1)=1
 * */

#include <stdio.h>

#define FIB(prev1, prev2, temp) ((temp=prev1), (prev1=prev1+prev2), (prev2=temp))

int main()
{
	int n, i=2;
	long long int prev1=1, prev2=0;
	printf("Input a number to calculate the fibonacci number\n");
	scanf("%d",&n);
	switch (n) {
		case 0:
			printf("Index = %d\tFibonacci No = %d\n", n, 0);
			break;
		case 1:
			printf("Index = %d\tFibonacci No = %d\n", n, 1);
			break;
		default:
			fibonacci(n, i, prev1, prev2);
			break;
	}
	return 0;
}

fibonacci(int n, int i, long long prev1, long long prev2)
{
	long long temp;
	if(i==n) {
		printf("Index = %d\tFibonacci No = %d\n", n, (prev1+prev2));
	}
	else {
		FIB(prev1, prev2, temp);
		fibonacci(n, i+1, prev1, prev2);
	}
}
