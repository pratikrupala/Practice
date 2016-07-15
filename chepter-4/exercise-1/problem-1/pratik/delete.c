#include <stdio.h>
#include <stdlib.h>

struct list{
	int         data;
	struct list *next;
};

void make_list(struct list **head, int length)
{
	int i = 0;
	struct list *tmp = NULL, *latest = NULL;

	for (i = 0; i < length; i++) {
		tmp = malloc(sizeof(struct list));
		if (!tmp) {
			fprintf(stderr, "Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
		tmp->data = 0;
		tmp->next = NULL;

		if (*head) {
			latest->next = tmp;
			latest = tmp;
		} else {
			*head = tmp;
			latest = tmp;
		}
	}
}

void print_list(struct list *head)
{
	int i = 1;
	struct list *iter = NULL;
	
	if (!head) {
		fprintf(stderr, "Empty list.\n");
		exit(EXIT_FAILURE);
	} else {
		for (iter = head; iter != NULL; iter = iter->next, i++) {
			printf("At position %d value: %d\n", i, iter->data);
		}
	}
}

void scan_list(struct list *head, int length)
{
	int i;
	struct list *iter = NULL;

	if (!head) {
		fprintf(stderr, "Empty list.\n");
		exit(EXIT_FAILURE);
	} else {
		for (iter = head, i = 1; i <= length, iter != NULL; iter = iter->next, i++) {
			printf("Enter the value of node at position: %d\n", i);
			scanf("%d", &(iter->data));
		}
	}
}

struct list *search_del(struct list *head, int del) 
{
	int i;
	struct list *current = head;
		
	if (!head) {
		fprintf(stderr, "Empty List.\n");
		exit(EXIT_FAILURE);
	} else {
		if (del == current->data) {
			return NULL;
		} else {
			while (current) {
				if(del == current->next->data)
					return current;
				current = current->next;
			}
			printf("Could not found node with value %d.\n", del);
			exit(EXIT_FAILURE);
		}
	}
}

void delete(struct list **head, struct list *node)
{
	struct list *tmp;
	if (node) {
		tmp = node->next;
		node->next = node->next->next;
	} else
		*head = (*head)->next;

	free(tmp);
}

int main(void)
{
	int l = 0, del = 0;
	struct list *head = NULL, *node = NULL;

	printf("Enter the length of link list:");
	scanf("%d", &l);
	if(l <= 0) {
		fprintf(stderr, "Invalid length of link list.\n");
		exit(EXIT_FAILURE);
	}

	make_list(&head, l);
	print_list(head);

	scan_list(head, l);
	printf("\nList after scan:\n");
	print_list(head);

	printf("Enter the value of node which needs to be deleted:");
	scanf("%d", &del);

	node = search_del(head, del);
	delete(&head, node);
	printf("\nList after deletion:\n");
	print_list(head);

	return 0;
}
