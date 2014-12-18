#include <stdio.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void perm(char *list, int i, int n)
{
	int j, tmp;
	printf("Entering in permutation function, list: %s and i:%d\n", list, i);
	if(i == n) {
	printf("Entering in ##if## condition list: %s and i:%d\n", list, i);
		for(j = 0; j <= n; j++) {
			printf("%c", list[j]);
		}
		printf("\n");
	}
	else {
	printf("Entering in else condition list: %s and i:%d\n", list, i);
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
