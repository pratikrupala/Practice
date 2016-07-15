#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct element {
	int data;
};

struct element stack[MAX_SIZE];
int top = -1;

void stackfull(void)
{
	printf("Stack is full, cannot add element.\n");
	exit(EXIT_FAILURE);
}

void push(struct element item)
{
	if (top >= (MAX_SIZE - 1))
		stackfull();

	stack[++top] = item;
}

void print_stack(void)
{
	int i;

	if (top == -1) {
		printf("No elements to print.\n");
	} else {
		for (i = top; i >= 0; i--) {
			printf("Value of element at position %d is: %d\n", i, stack[i].data);
		}
	}
}

int main(void)
{
	struct element *new;

	if ((new = (struct element *) malloc(sizeof(struct element))) == NULL) {
		printf("Failed to allocate memory for new element.\n");
		exit(EXIT_FAILURE);
	}

	new->data = 10;
	push(*new);

	printf("Stack:\n");
	print_stack();

	return 0;
}
