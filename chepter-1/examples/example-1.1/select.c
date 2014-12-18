#include <stdio.h>

#define MAX_COUNT 5
#define SWAP(a, b, t) ((t)=(a), (a)=(b), (b)=(t))

void sort(int set[], int n)
{
	int j, k, l, min, tmp;
	
	for(j = 0; j < n-1; j++) {
		min = j;
		for (k = j+1; k < n; k++) {
			if (set[k] < set[min])
				SWAP(set[k], set[min], tmp);
		}
	}

}

int main(void)
{
	int set[MAX_COUNT];
	int i = 0;

	for(i = 0; i < 5; i++) {
		set[i] = rand() % 100;
		printf("%d	", set[i]);
	}

	printf("\n");

	sort(set, MAX_COUNT);

	printf("Sorted numbers:\n");
	for(i = 0; i < 5; i++) {
                printf("%d      ", set[i]);
        }

	printf("\n");

	return 0;
}
