#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
	int val;
} element;

element queue[MAX_SIZE];
int f = -1;
int r = -1;

void fill_queue()
{
	element *new;
	int i;

	for (i = 1; i <= MAX_SIZE; i++) {
		if ((new = malloc(sizeof(element))) == NULL) {
			fprintf(stderr, "Failed to allocate memory for new elemnet.\n");
			exit(EXIT_FAILURE);
		}
		item->val = i * 10;
		insert(*item);
	}
}

int main(void)
{

	fill_queue();

	return 0;
}
