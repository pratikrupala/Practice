#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 3

struct item {
	int val;
};
int top = -1;
struct item my_stack[MAX_VAL];

void push(void)
{
	int input = -1;
	struct item *temp;

	if (top >= MAX_VAL - 1) {
		printf("Stack is full. New item cannot be pushed.\n");
		return;
	}
	printf("\nEnter the value to be pushed on the stack: ");
	scanf("%d", &input);

	temp = &my_stack[++top];

	temp->val = input;
}

void pop(void) {

	if (top < 0) {
		printf("\nStack is empty. Nothing is to be poped.\n");
		return;
	} else
		top--;
}

void print_stack(void) {
	int i = 0;

	if (top < 0) {
		printf("\nStack is empty. Nothing to be printed.\n");
		return;
	}

	printf("\nPrinting the values in the stack:\n");
	for (i = top; i >= 0; i--) {
		printf("%d\n", my_stack[i].val);
	}
}

int main(void)
{
	int choice = -1;
	while (1) {
		printf("\nPlease enter your choice: \n");
		printf("1. Push an item on stack.\n");
		printf("2. Pop an item from stach.\n");
		printf("3. Print the entire stack.\n");
		printf("4. Exit from the program.\n");

		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case  1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				print_stack();
				break;

			case 4:
				return 0;

			default:
				printf("Please enter the valid choice.\n");
				break;
		}
	}

	return 0;
}
