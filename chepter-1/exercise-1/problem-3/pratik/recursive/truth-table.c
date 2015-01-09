#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b, c) ((c) = (a), (a) = (b), (b) = (c))

void table(int n, char *s, int i)
{
	int j = 0;
	char c;
	char z = '0', o = '1';

	if(n == 0) {
		printf("%s", s);
		printf("\n");
		return;
	}
	
	SWAP(*(s+i), z, c);
	table(n - 1, s, i + 1);
	SWAP(*(s+i), o, c);
	table(n - 1, s, i + 1);
}

int main(void)
{
	char *s;
	int n = 0, i;

	printf("Enter the range of table:");
	scanf("%d", &n);

	s = (char *) malloc(n);

	table(n, s, 0);

	return 0;
}
