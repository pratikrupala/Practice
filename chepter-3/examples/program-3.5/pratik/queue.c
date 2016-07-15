#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
	int val;
} element;

element queue[MAX_SIZE];
int f = -1;
int r = -1;

void insert(element item)
{
	if (r == (MAX_SIZE - 1)) {
		fprintf(stderr, "No space left in queue to insert new element.\n");
		exit(EXIT_FAILURE);
	} else {
		queue[++r] = item;
	}
}

void print_queue(void)
{
	int i;

	for (i = (f + 1); i <= r; i++) {
		printf("Element value at position %d in queue is: %d\n", i, queue[i].val);
	}
}

void fill_queue(void)
{
	element *item;
	int i;

	for (i = 1; i <= MAX_SIZE; i++) {
		if ((item = malloc(sizeof(element))) == NULL) {
			fprintf(stderr, "Failed to allocate memory for new item.\n");
			exit(EXIT_FAILURE);
		}
		item->val = i * 10;
		insert(*item);
	}
}

int main(void)
{
	fill_queue();
	
	printf("Queue after insertion.\n");
	print_queue();

	return 0;
}
