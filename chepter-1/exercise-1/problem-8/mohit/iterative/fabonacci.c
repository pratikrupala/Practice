/*
 *Calculate the fabonacci function value to an input index number
 *f(i) = f(i-1) + f(i-2);	where f(0)=0 and f(1)=1
 * */
#include <stdio.h>

#define FAB(prev1, prev2, temp) ((temp=prev1), (prev1=prev1+prev2), (prev2=temp))

int main()
{
	int n;
	printf("Input a index i to which fabonacci function value\n");
	scanf("%d", &n);
	switch (n) {
		case 0:
			printf("Index = %d\tFabonacci number = %d\n", n, 0);
			break;
		case 1:
			printf("Index = %d\tFabonacci number = %d\n", n, 1);
			break;
		default:
			fabonacci(n);
			break;
	}
	return 0;
}

fabonacci(int n)
{
	long long int prev2=0, prev1=1;
	int temp,i;
	for(i=2; i<n; i++) {
		FAB(prev1, prev2, temp);
	}
	printf("Index = %d\tFabonacci number = %lld\n", n, (prev1+prev2));
	return 0;
}
