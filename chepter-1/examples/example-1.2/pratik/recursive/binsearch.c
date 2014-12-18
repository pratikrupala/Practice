#include <stdio.h>

#define MAX_COUNT 10
#define COMPARE(a, b) ((a < b)?-1:((a > b)?1:0))
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

void binsearch(int list[], int left, int right, int n)
{
	int middle, found = 0;

	if(left <= right) {
		middle = (left + right)/2;

		switch (COMPARE(list[middle], n)) {
			case -1:
				left = middle + 1;
				binsearch(list, left, right, n);
				break;
			case 0:
                                printf("Found the integer\n");
                                break;
			case 1:
				right = middle - 1;
				binsearch(list, left, right, n);
				break;
		}
	}
	else
		printf("Key not found\n");
}

int main(void)
{
	int arr[MAX_COUNT];
        int i = 0, n;

        for(i = 0; i < MAX_COUNT; i++) {
                arr[i] = rand() % 100;
                printf("%d      ", arr[i]);
        }
	printf("\n");

        sort(arr, MAX_COUNT);

        printf("Sorted numbers:\n");
        for(i = 0; i < MAX_COUNT; i++) {
                printf("%d      ", arr[i]);
        }

        printf("\n");

	printf("Enter a number to search:\n");
	scanf("%d", &n);

	binsearch(arr, 0, 9, n);

	return 0;
}
