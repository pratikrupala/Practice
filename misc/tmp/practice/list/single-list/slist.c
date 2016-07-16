#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <errno.h>

struct list {
	int data;
	struct list *next;
};

int make_list(struct list **h)
{
	int ret = 0;
	int len = -1;
	int i = 0;
	struct list *node = NULL;

	if (*h) {
		printf("\n**ERROR**: List is not empty.\n");
		ret = -EINVAL;
		goto out;
	}

	printf("\nEnter the length of the list: ");
	scanf("%d", &len);
	if (len <= 0) {
		printf("\n**ERROR**: Invalid length value.\n");
		ret = -EINVAL;
		goto out;
	}

	for (i = 0; i < len; i++) {
		if ((*h)) {
			node->next = (struct list *) malloc(sizeof(struct list));
			if (!(node->next)) {
				printf("\n**ERROR**: Failed to allocate memory "
					"for node at poistion %d.\n", (i + 1));
				ret = -ENOMEM;
				goto out;
			}
			node = node->next;
			printf("Enter the value of the node at position %d: ",
				(i + 1));
			scanf("%d", &(node->data));
		} else {
			*h = (struct list *) malloc(sizeof(struct list));
			if (!(*h)) {
				printf("\n**ERROR**: Failed to allocate the"
					" memory for head node.\n");
				ret = -ENOMEM;
				goto out;
			}
			printf("\nEnter the value of the node at position %d:"
				" ", (i + 1));
			scanf("%d", &((*h)->data));
			(*h)->next = NULL;
			node = *h;
		}
	}

out:
	return ret;
}

int add_node(struct list *h)
{
	int ret = 0;

	

	return ret;
}

void print_list(struct list *h)
{
	int i = 1;

	if (!h)
		printf("\n**ERROR**: Empty list.\n");

	while (h){
		printf("\nValue at position %d: %d", i, h->data);
		h = h->next;
	} 
	printf("\n");
}

int main(void)
{
	int ret = 0;
	int choice = -1;
	struct list *head = NULL;

	while (1) {
		choice = -1;
		printf("\nEnter your choice from the below menu:\n");
		printf("1. Create a new list.\n");
		printf("2. Add a new node in the list.\n");
		printf("3. Delete a node from the list.\n");
		printf("4. Print the list.\n");
		printf("5. exit.\n");
		printf("\nChoice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			ret = make_list(&head);
			if (ret) {
				printf("**ERROR**: Failed to create the list."
					"\n");
				goto exit;
			}
			break;
		case 2:
			ret = add_node(&head);
			if (ret) {
				printf("**ERROR**: Failed to add the node.\n");
				goto exit;
			}
			break;
		case 4:
			print_list(head);
			break;
		case 5:
			goto exit;
		default:
			printf("**ERROR**: Invalid choice.\n");
			break;
		}
	}

exit:
	return ret;
}
