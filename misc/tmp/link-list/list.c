#include <stdio.h>
#include <stdlib.h>

struct list {
	int val;
	struct list *next;
};

void mklist(struct list **head)
{
	struct list *current;
	int i = 0, len = 10;

	for (i = 1; i < len; i++) {
		if (*head) {
			if (((current->next) = malloc(sizeof(struct list))) == NULL) {
				fprintf(stderr, "Failed to allocate memory for intermediate node.\n");
				exit(EXIT_FAILURE);
			}
			current = current->next;
			current->val = 10 * i;
			current->next = NULL;
		} else {
			if ((*head = malloc(sizeof(struct list))) == NULL) {
				fprintf(stderr, "Failed to allocate memory for head of list.\n");
				exit(EXIT_FAILURE);
			}
			current = *head;
			current->val = 10;
			current->next = NULL;
		}
	}

}

void print_list(struct list *head)
{
	struct list *current = head;
	int i = 1;

	while (current != NULL) {
		printf("Value of node at index %d is: %d\n", i, current->val);
		i++;
		current = current->next;
	}
}

int main(void)
{
	struct list *head = NULL;

	mklist(&head);

	printf("Link list:\n");
	print_list(head);
	return 0;
}
