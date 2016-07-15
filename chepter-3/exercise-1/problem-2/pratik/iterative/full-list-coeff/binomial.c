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

void binomial_coeff(int n)
{
	struct element new = { .function_name = "binomial_coeff" };

	if (top >= MAX_SIZE) {
		fprintf(stderr, "Stack full.\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = new;

	printf("Printing stack at the entry of funtion.\n");
	print_stack();

	int i = 0, j = 0;

	for(i = 0; i < n; i++) {
		for(j = 0; j < (n - i - 1); j++)
			printf(" ");

		for(j = 0; j <= i; j++)
			printf("%d ", (factorial(i)/(factorial(j)*factorial(i - j))));
		
		printf("\n");
	}

	if (top < 0) {
		fprintf(stderr, "Stack is empty.\n");
		exit(EXIT_FAILURE);
	}
	stack[top--];

	printf("Printing stack at the exit of funtion.\n");
	print_stack();
}

int main(void)
{
	int n = 0;

	printf("Enter the value of degree(n):");
	scanf("%d", &n);

	if(n < 1) {
		printf("Invalid value of n.\n");
		exit(EXIT_FAILURE);
	}

	binomial_coeff(n);

	return 0;
}
