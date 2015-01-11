
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
	int disks;
	printf("Input the number of disk in the first tower\n");
	if (disks < 3) {
		printf("Number of disks must be greater then 03\n");
		printf("Please enter a valid number of disks\n");
		exit(0);
	}
	
}
