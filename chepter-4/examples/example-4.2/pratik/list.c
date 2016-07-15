#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
	if (!((p) = malloc(s))) {\
		fprintf(stderr, "Insufficient memory.\n");\
		exit(EXIT_FAILURE);\
	}

struct list {
	int         data;
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

		if(*head) {
			latest->next = tmp;
			latest = tmp;
		} else {
			*head = tmp;
			latest = tmp;
		}
	}
	

}

int main(void)
{
	struct list *head = NULL, *iter;
	int          n = 0;

	printf("Enter the length of list:");
	scanf("%d", &n);

	create(&head, n);

	for (iter = head; (iter != NULL); (iter = iter->next)) {
		printf("data: %d\n", iter->data);
	}

	return 0;
}
