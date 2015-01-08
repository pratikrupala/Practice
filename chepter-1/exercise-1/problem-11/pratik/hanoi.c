#include <stdio.h>

void hanoi(int disk, char src, char dest, char spare)
{
	if(disk == 1) {
		printf("Move disk %d from tower %c to tower %c\n", disk, src, dest);
		return;
	}

	hanoi(disk - 1, src, spare, dest);
	printf("Move disk %d from tower %c to tower %c\n", disk, src, dest);
	hanoi(disk - 1, spare, dest, src);
}

int main(void)
{
	int n = 0;

	printf("Enter the number of disks for the problem of tower of hanoi:");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}
