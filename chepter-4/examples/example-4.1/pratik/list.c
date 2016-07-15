#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list {
	char         data[4];
	struct list *next;
};

int main(void)
{
	struct list *first;

	if((first = malloc(sizeof(struct list))) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	strcpy(first->data, "BAT");
	first->next = NULL;

	printf("data: %s\n", first->data);

	return 0;
}
