#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10

struct node {
	char s;
	struct node *prev;
};

void subset(char *str, int n, struct node *up)
{
	struct node me;

	if(!n) {
		printf("{");
		while(up) {
			printf("%c", up->s);
			up = up->prev;
		}
		printf("}\n");
	} else {
		me.s = str[0];
		me.prev = up;
		subset((str + 1), (n - 1), up);
		subset((str + 1), (n - 1), &me);
	}

}

int main(void)
{
	char *str;
	int n = 0;

	if((str = (char *) malloc(MAXLEN)) == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	memset(str, 0, MAXLEN);

	printf("Enter any string:");
	scanf("%s", str);

	n = strlen(str);

	subset(str, n, 0);

	exit(EXIT_FAILURE);
}
