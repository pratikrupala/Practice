#include <stdio.h>
#include <stdlib.h>

struct element {
	char function_name[10];
};

struct element stack[10];
int top = -1;

void print_stack(void)
{
	int i;

	for (i = top; i > 0; i--) {
		printf("Value of function name at level %d is %s\n", i, stack[i].function_name);
	}
}

int fibonacci(int n)
{
	struct element new = { .function_name = "fibonacci" };
	if (top > 9) {
		fprintf(stderr, "Stack is full.\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = new;

	printf("Printing stack at the entrance of the function:\n");
	print_stack();

	static int a = 0;
	static int b = 1;
	int t = a;
	a = b;
	b = t + b;
	if(n > 1) {
		return fibonacci(n-1);
	}
	return t;
}

int main(void)
{
	int n = 0;
	int result = 0;

	printf("Enter a limiting number:");
	scanf("%d", &n);

	result = fibonacci(n);

	printf("result: %d\n", result);

	return 0;
}
