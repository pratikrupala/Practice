#include <stdio.h>
#include <malloc.h>
#include <math.h>

void toggle(int *x)
{
	if(*x == 1)
		*x = 0;
	else
		*x = 1;
}

void zero_out(int arr[], int n)
{
	int i;

	for(i = 0; i < n; i++) {
                arr[i] = 0;
        }
}

void generate_table(int counters[], int n)
{
	int limits[n], i, j, k = (pow(2, n)), m, table[n];

	zero_out(limits, n);	
	zero_out(table, n);	
	toggle(&table[0]);

	printf("Truth table for %d numbers:\n", n);
	for(i = 0; i < k; i++) {

		for(j = 1; j < n; j++) {
			if(limits[j] == (pow(2, j))) {
				toggle(&table[j]);
				limits[j] = 0;
			}
		}

		toggle(&table[0]);
		for(j = n-1; j >= 0; j--) {
			printf("%d	", table[j]);
		}
		printf("\n");

		for(j = 0; j < n; j++) {
			limits[j]++;
		}
	}
}

int main(void)
{
	int *counters, n =0, i;

	printf("Enter the number of bits for truth table:");
	scanf("%d", &n);

	counters = malloc((n * sizeof(int)));

	for(i = 0; i < n; i++) {
		counters[i] = pow(2, i);
	}

	for(i = 0; i < n; i++) {
		printf("counters[%d]: %d\n", i, counters[i]);
	}

	generate_table(counters, n);

	return 0;
}
