#include <stdio.h>

struct rectangle {
	int side_a;
	int side_b;
};

struct triangle {
	int side_a;
	int side_b;
	int side_c;
};

struct circle {
	int r;
};

int main(void)
{
	struct rectangle rect = { .side_a = 5, .side_b = 10 };
	struct triangle tri = { .side_a = 3, .side_b = 4, .side_c = 5 };
	struct circle cir = { .r = 7 };

	printf("\n");

	printf("Side A of rectangle: %d\n", rect.side_a);
	printf("Side B of rectangle: %d\n", rect.side_b);

	printf("\n");

	printf("Side A of triangle: %d\n", tri.side_a);
	printf("Side B of triangle: %d\n", tri.side_b);
	printf("Side C of triangle: %d\n", tri.side_c);

	printf("\n");

	printf("Redius of circle: %d\n", cir.r);

	printf("\n");

	return 0;
}
