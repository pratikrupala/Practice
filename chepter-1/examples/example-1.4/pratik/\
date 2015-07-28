#include <stdio.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void perm(char *list, int i, int n)
{
	int j, tmp;
	if(i == n) {
		for(j = 0; j <= n; j++) {
			printf("%c", list[j]);
		}
		printf("\n");
	}
	else {
		for(j = i; j <= n; j++) {
			SWAP(list[i], list[j], tmp);
			perm(list, i+1, n);
			SWAP(list[j], list[i], tmp);
		}
	}
}

int main(void)
{
	char list[] = "abcd";

	perm(list, 0, 3);
	return 0;
}
