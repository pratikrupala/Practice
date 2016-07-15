#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)\
	if (!((p) = malloc(s))) {\
		fprintf(stderr, "Insufficient memory.");\
		exit(EXIT_FAILURE);\
	}

struct list {
	int          data;
	struct list *next;
};

void create(struct list **head, int n)
{
	struct list *tmp, *latest;
	int          i;

	for (i = 1; i <= n; i++) {
		MALLOC(tmp, sizeof(struct list));

		tmp->data = i * 10;
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
	struct list *iter;
	int          i;

	if (head == NULL) {
		printf("It's an empty list.\n");
	} else {
		for (iter = head, i = 1; iter != NULL; iter = iter->next, i++) {
			printf("item: %d and data: %d\n", i, iter->data);
		}
	}
}

void insert(struct list **head, int position, int value)
{
	struct list *new, *current = *head, *last = *head;
	int          i = 1;

	MALLOC(new, sizeof(struct list));
	new->data = value;
	new->next = NULL;

	if (*head) {
		while (current != NULL) {
			if (i == position) {
				if (i == 1) {
					new->next = last;
					*head = new;
				} else {
					new->next = last->next;
					last->next = new;
				}
			}
			i++;
			last = current;
			current = current->next;
		}
	} else {
		*head = new;
		new->data = value;
	}
}

void delete(struct list **head, int index)
{
	struct list *tmp, *current = *head;
	int i;

	if (index == 1) {
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}

	for (i = 1; (i <= index) && (current != NULL); i++) {
		if (i == (index - 1)) {
			if (current->next->next != NULL) {
				tmp = current->next;
				current->next = tmp->next;
				free(tmp);
			} else {
				free(current->next);
				current->next = NULL;
			}
		}
		current = current->next;
	}

}

int main(void)
{
	struct list *head = NULL;
	int          n = 0, p = 0;
	int          val = 0;
	int	     choice = 0;
	int 	     del = 0;

	printf("Enter the length of list:");
	scanf("%d", &n);
	if (n <= 0) {
		fprintf(stderr, "Invalid length of list.");
		exit(EXIT_FAILURE);
	}

	create(&head, n);

	printf("List before insertion:\n");
	print_list(head);

	while (1) {
		printf("1: Node insertion.\n");
		printf("2: Node deletion.\n");
		printf("3: Exit.\n");
		printf("Enter your choice from below mentioned operations:\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter the position for insertion:");
				scanf("%d", &p);
				if (p <= 0 || p > n) {
        	        		fprintf(stderr, "Invalid position for insertion.");
                			exit(EXIT_FAILURE);
        			}

				printf("Enter the value of data to be inserted:");
				scanf("%d", &val);
	
				insert(&head, p, val);

				printf("List after insertion:\n");
				print_list(head);
				break;

			case 2:
				printf("Enter the index of node to be deleted:");
				scanf("%d", &del);
				if (del <= 0 || del > n) {
                                        fprintf(stderr, "Invalid position for deletion.");
                                        exit(EXIT_FAILURE);
                                }
				delete(&head, del);
				printf("List after deletion:\n");
				print_list(head);
				break;

			case 3:
				goto out;

			default:
				printf("Invalide choice.\n");
				break;
		}
	}
out:
	return 0;
}
