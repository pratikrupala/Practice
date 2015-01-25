
/*[Tower of Hanoi] There are three towers and 64 disks of
 *different diameter placed on the first tower. The disks are 
 *in decreasing order as one scans up the tower. Monks are
 *reputedly suppose to move the disk from tower 1 to tower 3 
 *obeying the rules:
 *1. only one disk can be moved at any time.
 *2. No disk can be placed on top of a disk with a smaller diameter
 *Write a recursive function that prints out the sequence of moves 
 *need to accomplish this task.
 * */

#include <stdio.h>
#include<stdlib.h>

int main()
{
	int disks, curr_tower=1, targ_tower=3, other_tower=2;
	printf("Input the number of disk in the first tower\n");
	scanf("%d", &disks);
	if (disks < 3) {
		printf("Number of disks must be greater then 03\n");
		printf("Please enter a valid number of disks\n");
		exit(0);
	}
	toh(disks, curr_tower, targ_tower, other_tower);
}

toh(int disks, int curr_tower, int targ_tower, int other_tower)
{
	if(disks == 3)
	{
		move_targ_tower(curr_tower, targ_tower, other_tower);
	}
	else {
		toh(disks-1, curr_tower, other_tower, targ_tower);
		if(disks-1 == 3) {
			printf("Put disk no %d to %d tower\n", disks, targ_tower);
			toh(disks-1, other_tower, targ_tower, curr_tower);	
		}
		printf("Put disk no %d to %d tower\n", disks, other_tower);
		if (disk-1 >= 3) {
			toh(disk-1, );
		}
	}
}

move_targ_tower(int curr_tower, int targ_tower, int other_tower)
{
	printf("Put disk no %d to %d tower\n", 1, targ_tower);
	printf("Put disk no %d to %d tower\n", 2, other_tower);
	printf("Put disk no %d to %d tower\n", 1, other_tower);
	printf("Put disk no %d to %d tower\n", 3, targ_tower);
	printf("Put disk no %d to %d tower\n", 1, curr_tower);
	printf("Put disk no %d to %d tower\n", 2, targ_tower);
	printf("Put disk no %d to %d tower\n", 1, targ_tower);
	
}
