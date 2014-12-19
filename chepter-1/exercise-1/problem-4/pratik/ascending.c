#include <stdio.h>

int min(int m, int n)
{
	if(m < n)
		return 1;
	else
		return 0;
}

void print_ascending(int a, int b, int c)
{
	if(min(a, b) && min(a, c)) {
		printf("%d\n", a);
		if(min(b, c))
			printf("%d\n%d\n", b, c);
		else
			printf("%d\n%d\n", c, b);
	}
	else if(min(b, a) && min(b, c)) {
		printf("%d\n", b);
                if(min(a, c))
                        printf("%d\n%d\n", a, c);
                else
                        printf("%d\n%d\n", c, a);
	}
	else {
		printf("%d\n", c);
                if(min(a, b))
                        printf("%d\n%d\n", a, b);
                else
                        printf("%d\n%d\n", b, a);
	}
}

int main(void)
{
	int x = 0, y = 0, z = 0;

	printf("Please enter the values of x:\n");
	scanf("%d", &x);

	printf("Please enter the values of y:\n");
	scanf("%d", &y);

	printf("Please enter the values of z:\n");
	scanf("%d", &z);

	printf("You have entered x: %d, y: %d and z: %d\n", x, y, z);

	print_ascending(x, y, z);

	return 0;
}
