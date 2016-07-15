#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct element {
	char function_name[15];
};

struct element stack[MAX_SIZE];
int top = -1;

int factorial(int a)
{
	int i = 0, res = 1;

	for(i = a; i > 0; i--) {
		res *= i;
	}

	return res;
}

void print_stack(void)
{
	int i = 0;

	for (i = top; i >= 0; i--) {
		printf("%s\n", stack[i].function_name);
	}
}

int binomial_coeff(int n, int k)
{
	struct element new = { .function_name = "binomial_coeff" };

	if (top >= MAX_SIZE) {
		fprintf(stderr, "Stack full.\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = new;

	printf("Printing stack before entrin in the fuction:\n");
	print_stack();

	return (factorial(n)/(factorial(k)*factorial(n - k)));
}

int main(void)
{
	int n = 0, k = 0, r = 0;

	printf("Enter the value of degree(n):");
	scanf("%d", &n);

	if(n < 1) {
		printf("Invalid value of n.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the value of k:");
	scanf("%d", &k);

	if(k < 0) {
		printf("Invalid value of k.\n");
		exit(EXIT_FAILURE);
	}

	r = binomial_coeff(n, k);

	printf("Binomial coefficient of given numbers is %d\n", r);

	return 0;
}
