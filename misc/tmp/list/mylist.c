#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

void my_add_node(struct mynode **head)
{
	int val = 0;
	int choice = -1;
	struct mynode *new = NULL;

	printf("\n\tEnter your choice for node addition.\n");
	printf("\t\t[1] Addition at the front of the list.\n");
	printf("\t\t[2] Addtion at the end of the list.\n");
	printf("\t\t[3] Addtion at middle of the list.\n");

	printf("\tNode addition choice: ");
	scanf("%d", &choice);

	printf("\n\tEnter value of new node: ");
	scanf("%d", &val);

	if (choice == 1) {
		if (!(*head)) {
                        *head = malloc(sizeof(struct mynode));
                        if (!(*head)) {
                                printf("\tFailed to allocate memory for new "
					"node.\n");
                                return;
                        }
                        (*head)->data = val;
                        (*head)->next = NULL;
                } else {
			new = malloc(sizeof(struct mynode));
			if (!new) {
				printf("\tFailed to allocate memory for new "
					"node.\n");
				return;
			}
			new->data = val;
			new->next = *head;
			*head = new;
		}
	} else if (choice == 2) {
		if (!(*head)) {
			*head = malloc(sizeof(struct mynode));
			if (!(*head)) {
				printf("\tFailed to allocate memory for new "
					"node.\n");
				return;
			}
			(*head)->data = val;
			(*head)->next = NULL;
		} else {
			new = *head;
			while (new->next != NULL) {
				new = new->next;
			}
			new->next = malloc(sizeof(struct mynode));
			if (!(new->next)) {
        	                printf("\tFailed to allocate memory for new node.\n");
                	        return;
                	}
			new->next->data = val;
			new->next->next = NULL;
		}
	} else if (choice == 3) {
		int i = -1;
		int position = -1;
		struct mynode *node = *head;
		printf("\n\tEnter the position at which node is to be "
			"inserted: ");
		scanf("%d", &position);
		if (position < 0) {
			printf("\tInvalid position. Please try again.\n");
		}
		for (i = position; (i > 1) && (node); i--) {
			node = node->next;
		}
		if (i != 1) {
			printf("No such position as %d in list.\n", position);
			return;
		}
		new = malloc(sizeof(struct mynode));
		if (!new) {
			printf("\tFailed to allocate memory for new node.\n");
			return;
		}
		new->data = val;
		new->next = node->next;
		node->next = new;
	} else {
		printf("\tWrong choice for addition. Please try again.\n");
	}
}

void my_delete_node(struct mynode **head)
{

}

void my_search_node(struct mynode *head)
{

}

void my_print_list(struct mynode *head)
{
	printf("\n\tValues in link list:\n");
	while (head) {
		printf("\t%d", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(void)
{
	struct mynode *head = NULL;
	int choice = -1;

	while (1) {
		printf("\nEnter a choice from below menu:\n");
		printf("[1] for Add a node in list.\n");
		printf("[2] for Remove a node in list.\n");
		printf("[3] for searching a node value in list.\n");
		printf("[4] for printing a node values in list.\n");
		printf("[5] for ending the program.\n");

		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			my_add_node(&head);
			break;
		case 2:
			my_delete_node(&head);
			break;
		case 3:
			my_search_node(head);
			break;
		case 4:
			my_print_list(head);
			break;
		case 5:
			goto out;
		default:
			printf("Wrong choice. Try again.\n");
		}
	}

out:
	return 0;
}
