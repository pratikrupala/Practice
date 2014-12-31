/*
 *Print x,y,z in ascending order
 *
 * */
#include <stdio.h>

#define MIN(a,b) (a==b)?a:(a<b)?a:b

int main()
{
	int x,y,z,min, inter_min;
	printf("Input the first No.\n");
	scanf("%d",&x);
	printf("Input the Second No.\n");
	scanf("%d",&y);
	printf("Input the Third No.\n");
	scanf("%d",&z);
	inter_min = MIN(x,y);
	min = MIN(inter_min, z);
	printf("Min = %d\n", min);			
	if(x == min) {
		if (y <= z)
			printf("%d %d %d\n", x, y, z);	
		else
			printf("%d %d %d\n", x, z, y);
	}
	else if (y == min) {
		if (x <= z)
			printf("%d %d %d\n", y, x, z);
		else
			printf("%d %d %d\n", y, z, x);
	}
	else
		if (x <= y)
			printf("%d %d %d\n", z, x, y);
		else
			printf("%d %d %d\n", z, y, x);
	return 0;
}
