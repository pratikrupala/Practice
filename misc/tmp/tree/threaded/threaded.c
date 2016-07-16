#include <stdio.h>

struct tree_node {
	bool left_thread;
	struct tree_node *left_child;
	int data;
	struct tree_node *right_child;
	bool right_thread;
};

void add_left_child(struct tree_node *node, int data)
{
	
}

void  create_tree(struct tree_node **head)
{
	struct tree_node *root = NULL;

	*head = (struct tree_node *) malloc(sizeof(struct tree_node));
	if (!(*head)) {
		printf("**ERROR**: Failed to allocate memory for head"
			" node.\n");
		exit(EXIT_FAILURE);
	}

	(*head)->left_thread = false;
	(*head)->left_child = NULL;
	(*head)->data = 0;
	(*head)->right_child = *head;
	(*head)->right_tread = false;

	root = (struct tree_node *) malloc(sizeof(struct tree_node));
	if (!root) {
		printf("**ERROR**: Failed to allocate memory for root"
			" node.\n");
		exit(EXIT_FAILURE);
	}

	root->left_thread = true;
	root->left_child = *head;
	root->data = 1;
	root->right_child = *head;
	root->right_thread = true;

	add_left_child(*head, 2);
}

int main(void)
{
	struct tree_node *head = NULL;

	create_tree(&head);

	return 0;
}
