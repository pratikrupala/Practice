#include <stdio.h>
#include <stdlib.h>

struct element {
	char function_name[15];
};

struct element stack[10];
int top = -1;

void print_stack(void)
{
	int i = 0;

	for (i = top; i >=0 ; i--) {
		printf("%s with top: %d\n", stack[i].function_name, top);
	}
}

int factorial(int n)
{
	struct element new = { .function_name = "factorial" };
	
	if (top > 9) {
		fprintf(stderr, "stack full.\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = new;

	printf("Printing stack at the entry of function:\n");
	print_stack();

	int i;

	if(n < 1)
		return 1;
	else {
		return n * factorial(n-1);
	}
}
