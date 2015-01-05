#include <stdio.h>
#include <stdlib.h>

int akermann(int a, int b)
{
	int list[100000];
	int i = 1;

	list[0] = a;
	list[1] = b;

	do {
		if(list[i-1] == 0) {
		 	i -= 1;
			list[i] = list[i+1] + 1;
		}
		else if(list[i] == 0) {
			list[i] = 1;
			list[i-1] = list[i-1] - 1;
		}
		else {
			list[i+1] = list[i] - 1;
			list[i] = list[i-1];
			list[i-1] = list[i-1] - 1;
			i += 1;
		}
	} while(i != 0);
	
	return list[0];
}

int main(void)
{
	int m = 0, n = 0, r = 0;

	printf("Enter the value of m:");
	scanf("%d", &m);

	if(m < 0) {
		printf("You have entered wrong value of m.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the value of n:");
	scanf("%d", &n);

	if(n < 0) {
		printf("You have entered wrong value of n.\n");
		exit(EXIT_FAILURE);
	}

	r = akermann(m, n);

	printf("Result of Akermann's function: %d\n", r);

	return 0;
}
