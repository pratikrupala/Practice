#include <stdio.h>
#include <malloc.h>

#define MOD(a, b) (a % b)

void evaluate_pigeonhole(int list[], int n)
{
	int op[n], locked[n];
	int i, j, printed = 0;

	for(i = 0; i < n; i++) {
		locked[i] = 0;
	}

	for(i = 0; i < n; i++) {
		op[i] = MOD(list[i], 10);
		for(j = i-1; j >= 0; j--) {
			if(op[i] == op[j]) {
				locked[i]++;
				locked[j]++;
			}
		}
	}
	
	for(i = 0; i < n; i++) {
		if(locked[i]) {
			printf("Found input value: %d\n", list[i]);
			printed++;
		}
	}
	
	if(!printed)
		printf("No inputs aligns pigeonhole principle\n");
}

int main(void)
{
	int *inp;
	int l = 0;
	int i;

	printf("Please enter the length of array of input values:");
	scanf("%d", &l);

	inp = malloc(l * sizeof(int));

	printf("Enter the input values\n");
	for(i = 0; i < l; i++) {
		scanf("%d", &inp[i]);
	}

	printf("List of entries in input\n");
	for(i = 0; i < l; i++) {
                printf("%d	", inp[i]);
        }

	printf("\n");

	evaluate_pigeonhole(inp, l);

	return 0;
}
