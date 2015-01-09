/*
 *Ackermann's function A(m,n) is defined as 
 *		n+1			if m=0
 *A(m,n)	A(m-1,1)		if m>0 and n=0
 * 		A(m-1, A(m, n-1))	if m>0 and n>0
 *WAP to compute ackermann's function using recursive and iterative method 
 * */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m, n, result;
	printf("Input the value of m\n");
	scanf("%d", &m);
	printf("Input the value of n\n");
	scanf("%d", &n);
	
	if (m < 0 && n < 0) {
		printf("Please enter the correct input\n");
		exit(-1);
	}
	result = acker_fun(m, n);
	printf("Ackermann's function output for m = %d\tn = %d\tresult = %d\n", m, n, result);
}

acker_fun(int m, int n)
{
	if (m == 0) {
		return (n+1);
	}
	else if (m > 0 && n == 0) {
		return (acker_fun(m-1, 1));
	}
	else if(m > 0 && n > 0) {
		return (acker_fun(m-1, (acker_fun(m, n-1))));
	}
}
