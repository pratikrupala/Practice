#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n, result = 0;
	printf("Input the value of m\n");
	scanf("%d", &m);
	printf("Input the value of n\n");
	scanf("%d", &n);
	if (m < 0 || n < 0) {
		printf("Please Input the correct values of m and n\n");
		exit (-1);
	}
	result = acker_fun(m,n);
	printf("Ackermann's function value for m = %d\tn = %d\tresult = %d\n", m, n, result);
	return 0;
}

acker_fun(int m, int n)
{
	int result;
	if (m == 0) {
		result = cond1(n);
	}
	else if (m > 0 && n == 0) {
		result = cond2(m, n);
	}
	else if (m > 0 && n > 0) {
		result = cond3(m, n);
	}
	return result;
}

cond1(int n)
{
	printf("In cond1\n");
	printf("Condition 1 result=%d\n", (n+1));
	return (n+1);
}
cond2(int m, int n)
{
	printf("In cond2\n");
	int result;
	m = m-1;
	n = 1;
	if (m == 0) {
		result = cond1(n);
	}
	else if (m > 0 && n == 0) {
		result = cond2(m, n);
	}
	else if (m > 0 && n > 0) {
		result = cond3(m, n);
	}
	printf("Condition 2 result=%d\n", result);
	return result;
}

cond3(int m, int n) 
{
	printf("In cond3\n");
	int result;
	n = n-1;
	if (n == 0) {
		result = cond2(m, n);
	}
	else if(n > 0) {
		result = cond3(m, n);
	}
	m = m-1;
	n = result;
	if (m == 0) {
		result = cond1(n);
	}
	else if (m > 0 && n == 0) {
		result = cond2(m, n);
	}
	else if (m > 0 && n > 0) {
		result = cond3(m, n);
	}
	printf("Condition 3 result=%d\n", result);
	return result;
}
