#include <stdio.h>
#include <stdlib.h>

struct tree_node {
	struct tree_node *left_child;
	int data;
	struct tree_node *right_child;
};

void add_left_child(struct tree_node *node, int data)
{
	if (node->left_child) {
		printf("**ERROR**: Invalid case, left child not NULL.\n");
		exit(EXIT_FAILURE);
	}

	node->left_child = (struct tree_node *) 
				malloc(sizeof(struct tree_node));
	if (!(node->left_child)) {
		printf("**ERROR**: Failed to allocate memory for left"
			" child.\n");
		exit(EXIT_FAILURE);
	}
	node->left_child->data = data;
}

void add_right_child(struct tree_node *node, int data)
{
	if (!node) {
		printf("**ERROR**: Invalid case. Node is NULL while adding"
			"right child.\n");
		exit(EXIT_FAILURE);
	}

	node->right_child = (struct tree_node *)
				malloc(sizeof(struct tree_node));
	if (!(node->right_child)) {
		printf("**ERROR**: Failed to allocate memory for right child"
			"of node with value: %d", node->data);
		exit(EXIT_FAILURE);
	}
	node->right_child->data = data;
}

void generate_tree(struct tree_node **root)
{
	*root = (struct tree_node *) malloc(sizeof(struct tree_node));
	if (!(*root)) {
		printf("**ERROR**: Failed to allocate memory for root"
			" node.\n");
		exit(EXIT_FAILURE);
	}
	(*root)->data = 1;
	
	add_left_child(*root, 2);
	add_right_child(*root, 3);
	add_left_child((*root)->left_child, 4);
	add_right_child((*root)->left_child, 5);
	add_left_child((*root)->right_child, 6);
	add_right_child((*root)->right_child, 7);
	add_left_child(((*root)->left_child)->left_child, 8);
	add_right_child(((*root)->right_child)->right_child, 11);
}

void vlr(struct tree_node *root)
{
	if(root) {
		printf("%d", root->data);
		vlr(root->left_child);
		vlr(root->right_child);
	}
}

int main(void)
{
	struct tree_node *root = NULL;

	generate_tree(&root);

	printf("\nVLR: ");
	vlr(root);
	printf("\n\n");

	return 0;
}
