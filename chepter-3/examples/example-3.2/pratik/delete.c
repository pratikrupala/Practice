#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
	int val;
} element;

element stack[MAX_SIZE];
int top = -1;

void stackfull(void)
{
	fprintf(stderr, "Stack is full, cannot push new element.\n");
	exit(EXIT_FAILURE);
}

void push(element item)
{
	if (top >= (MAX_SIZE - 1))	
		stackfull();

	stack[++top] = item;
}

int stack_empty(void)
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void print_stack(void)
{
	int i;

	if (stack_empty()) {
		printf("No element to print.\n");
	} else {
		for (i = top; i >= 0; i--) {
			printf("Value of element at index %d is: %d\n", i, stack[i].val);
		}
	}
}

void delete(void)
{
	if (stack_empty()) {
		printf("No element to delete.");
	} else {
		stack[top--];
	}
}

int main(void)
{
	int k;
	
	for (k = 1; k <= 10; k++) {
		element *new;

		if ((new = malloc(sizeof(element))) == NULL) {
	 		fprintf(stderr, "Fialed to allocate memory for new item.\n");
			exit(EXIT_FAILURE);
		}

		new->val = k * 10;
		push(*new);
	}

	printf("Stack:\n");
	print_stack();

	delete();
	printf("\nStack:\n");
	print_stack();

	return 0;
}
