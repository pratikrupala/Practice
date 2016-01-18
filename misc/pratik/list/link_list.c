#include <stdio.h>
#include <stdlib.h>

struct my_list {
	int val;
	struct my_list *next;
};

int list_length = 0;

void create_list(struct my_list **head)
{
	int n = -1, i = 0;
	struct my_list *temp = NULL, *last = NULL;

	printf("\nEnter the number nodes in the list: ");
	scanf("%d", &n);

	if (*head) {
		printf("List is not empty, not allowed to create the new list.\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		temp = (struct my_list *) malloc(sizeof(struct my_list));

		printf("Enter the value for the node number %d: ", i + 1);
		scanf("%d", &(temp->val));
		temp->next = NULL;
	
		if (*head) {
			last->next = temp;
		} else {
			*head = temp;
		}
		last = temp;
		list_length += 1;
	}
}

void print_list(struct my_list *head)
{
	printf("\nPrinting the list.\n");

	if (!head) {
		printf("List is empty. Nothing to print.\n");
		return;
	}

	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}
	printf("\n");
}

void add_node_at_front(struct my_list **head)
{
        struct my_list *temp = NULL;

        temp = (struct my_list *) malloc(sizeof(struct my_list));

        printf("\nEnter the value of new node: \n");
        scanf("%d", &(temp->val));
        temp->next = NULL;

	if (*head) {
		temp->next = *head;
		*head = temp;
	} else {
		*head = temp;
	}
	list_length += 1;
}

void add_node_at_end(struct my_list **head)
{
	struct my_list *temp = NULL, *last = *head;

	temp = (struct my_list *) malloc(sizeof(struct my_list));

	printf("\nEnter the value of new node: \n");
	scanf("%d", &(temp->val));
	temp->next = NULL;

	if (last) {
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = temp;
	} else {
		*head = temp;
	}
	list_length += 1;
}

void node_addition_at_location(struct my_list **head)
{
	int location = -1, len = 1;
	struct my_list *temp = *head, *new = NULL;

	printf("Enter the position in list for node insertion: ");
	scanf("%d", &location);

	if (location < 1 || location > (list_length + 1)) {
		printf("Invalid location.\n");
		exit(EXIT_FAILURE);
	}

	new = (struct my_list *) malloc(sizeof(struct my_list));

	printf("Enter the value of new node: ");
	scanf("%d", &(new->val));

	if (location == 1) {
		new->next = *head;
		*head = new;
	} else {
		while (temp) {
			if (len == (location - 1))
				break;
			len++;
			temp = temp->next;
		}


		new->next = temp->next;
		temp->next = new;	
	}
	list_length += 1;
}

void node_addition_after_value(struct my_list **head)
{
	struct my_list *temp = *head, *new = NULL;
	int search_val = -1, found = 0;

	printf("Enter the value of node after which node need to be inserted: ");
	scanf("%d", &search_val);

	if (search_val < 0) {
		printf("Invalid value of node entered.\n");
		exit(EXIT_FAILURE);
	}

	new = (struct my_list *) malloc(sizeof(struct my_list));
	printf("Enter the value of new node: ");
	scanf("%d", &(new->val));

	while (temp) {
		if ((temp->val) == search_val) {
			found = 1;
			break;
		}
		temp = temp->next;
	}

	if (found) {
		new->next = temp->next;
		temp->next = new;
	} else {
		printf("No node with value %d found.\n", search_val);
	}

	list_length += 1;
}

void add_node_at_specific_location(struct my_list **head)
{
	int sub_choice = -1;

	printf("Enter the sub-choice to add a node.\n");
	printf("\t1. Enter a node at a specific location.\n");
	printf("\t2. Enter a node after certain value of a node.\n");
	printf("Sub-choice: ");
	scanf("%d", &sub_choice);

	switch (sub_choice) {
		case 1:
			node_addition_at_location(head);
			break;
		case 2:
			node_addition_after_value(head);
			break;
		default:
			printf("Please enter valid sub-choice.\n");
			break;
	}
}

struct my_list *search_node(struct my_list *head)
{
	int value = -1;

	printf("Enter the value of the node to be searched: ");
	scanf("%d", &value);

	while (head) {
		if (head->val == value)
			return head;
		head = head->next;
	}
	printf("No node with value %d.\n", value);
	return NULL;
}

void check_node(struct my_list *my_node)
{
	printf("Value of my node: %d\n", my_node->val);
}

void cleanup_list(struct my_list **head)
{
	struct my_list *temp = *head;
	while (temp) {
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	list_length = 0;
}

int main()
{
	int choice = -1;
	struct my_list *head = NULL, *my_node = NULL;

	while (1) {
		printf("\nPlease enter your choice:\n");
		printf("\t1. Create a new list.\n");
		printf("\t2. Print the entire list.\n");
		printf("\t3. Add a node at the front of list.\n");
		printf("\t4. Add a node at the end of list.\n");
		printf("\t5. Add a node at a specified location of list.\n");
		printf("\t6. Search a node in the list.\n");
		printf("\t7. Exit from the program.\n");

		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				create_list(&head);
				break;

			case 2:
				print_list(head);
				break;

			case 3:
				add_node_at_front(&head);
				break;

			case 4:
				add_node_at_end(&head);
				break;

			case 5:
				add_node_at_specific_location(&head);
				break;

			case 6:
				my_node = search_node(head);
				if (my_node)
					check_node(my_node);
				break;

			case 7:
				cleanup_list(&head);
				goto out;
				break;

			default:
				printf("Please enter a valid choice.\n");
				break;
		}
	}
out:
	return 0;
}
