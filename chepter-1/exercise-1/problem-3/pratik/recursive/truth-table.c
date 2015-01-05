#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void truth_table(int *table, int n, int i)
{
	if(i == n) {
		int j;
		for(j = 0; j < n; j++)
			printf("%d ", table[j]);

		printf("\n");
	}
	else {
		int k = 0, l = 0;
		for(k = 0; k < 2; k++) {
			truth_table(table, n, i+1);
			table[i] = 1;
			for(l = i+1; l < n; l++)
				table[l] = 0;
		}
	}
}

int main(void)
{
	int n = 0, *table, i = 0;

	printf("Enter the number of bits for truth table:");
	scanf("%d", &n);

	if(n < 1) {
		printf("You have entered a wrong input for n.\n");
		exit(EXIT_FAILURE);
	}

	if(((table = malloc((n * sizeof(int)))) == NULL)) {
		printf("Unable to locate memory.\n");
		exit(EXIT_FAILURE);
	}

	memset(table, 0, sizeof(n * sizeof(int)));

	truth_table(table, n, i);

	return 0;
}
