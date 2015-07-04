#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 20
#define COMPARE(a,b) (((a) < (b)) ? -1: ((a) == (b)) ? 0: 1)

int avail = 0;

typedef struct {
	float coef;
	int expo;
} polynomial;

polynomial consolidated[MAX_COUNT];

void read_poly()
{
	printf("Keep entering coefficient and exponent of the polynomial and"
	       " enter -1 for exponent at the end.\n");

	while (1) {
		printf("Exponent:");
		scanf("%d", &consolidated[avail].expo);
		if (consolidated[avail].expo < 0)
			break;

		printf("Coefficient:");
		scanf("%f", &consolidated[avail].coef);
	
		avail++;
	}
}

void print_poly(int start, int end)
{
	int i;

	printf("%.2fx^%d ", consolidated[start].coef, consolidated[start].expo);
	for (i = start + 1; i <= end; i++) {
		if (consolidated[i].expo != 0)
			printf("+ %.2fx^%d ", consolidated[i].coef, consolidated[i].expo);
		else
			printf("+ %.2f ", consolidated[i].coef);
	}
	printf("\n");

}

int attach_term(int expo, float coef)
{
	if (avail == MAX_COUNT)
		return -1;

	consolidated[avail].expo = expo;
	consolidated[avail].coef = coef;

	avail++;

	return 0;
}

void add_poly(int first_start, int first_end, int second_start, int second_end,
					int *result_start, int *result_end)
{
	int ret = -1;
	float coefficient = 0;

	*result_start = avail;

	while (first_start <= first_end && second_start <= second_end) {
		switch (COMPARE(consolidated[first_start].expo, 
				consolidated[second_start].expo)) {
		case -1:
//			printf("A is less than B. B = %d\n", consolidated[second_start].expo);
			ret = attach_term(consolidated[second_start].expo,
						consolidated[second_start].coef);
			if (ret < 0) {
				fprintf(stderr, "Array is full. Polynomial addition failed.\n");
				exit(EXIT_FAILURE);
			}
			second_start++;
			break;
		case 0:
			coefficient = consolidated[first_start].coef
					 + consolidated[second_start].coef;
//			printf("A is equal to B. A = %d and B = %d\n",
//				consolidated[first_start].expo,	consolidated[second_start].expo);
			ret = attach_term(consolidated[second_start].expo,
		                                                coefficient);
                        if (ret < 0) {
                                fprintf(stderr, "Array is full. Polynomial addition failed.\n");
                                exit(EXIT_FAILURE);
                        }
			first_start++;
			second_start++;
			break;
		case 1:
//			printf("A is greater than B. A = %d\n", consolidated[first_start].expo);
			ret = attach_term(consolidated[first_start].expo,
						consolidated[first_start].coef);
                        if (ret < 0) {
                                fprintf(stderr, "Array is full. Polynomial addition failed.\n");
                                exit(EXIT_FAILURE);
                        }
			first_start++;
			break;
		}
	}

	for (; first_start <= first_end; first_start++) {
//		printf("Remaining A = %d\n", consolidated[first_start].expo);
		ret = attach_term(consolidated[first_start].expo,
                                                consolidated[first_start].coef);
                        if (ret < 0) {
                                fprintf(stderr, "Array is full. Polynomial addition failed.\n");
                                exit(EXIT_FAILURE);
                        }

	}

	for (; second_start <= second_end; second_start++) {
//		printf("Remaining B = %d\n", consolidated[second_start].expo);
		ret = attach_term(consolidated[second_start].expo,
                                                consolidated[second_start].coef);
                        if (ret < 0) {
                                fprintf(stderr, "Array is full. Polynomial addition failed.\n");
                                exit(EXIT_FAILURE);
                        }

	}

	*result_end = avail - 1;
}

int main(void)
{
	int start_of_first = 0;
	int end_of_first = 0;
	int start_of_second = 0;
	int end_of_second = 0;
	int start_of_final = 0;
	int end_of_final = 0;

	printf("Enter the polynomial A.\n");
	read_poly();
	end_of_first = avail - 1;

	printf("\n");

	start_of_second = avail;
	printf("Enter the polynomial B.\n");
	read_poly();
	end_of_second = avail - 1;

	add_poly(start_of_first, end_of_first, start_of_second, end_of_second, 
		 &start_of_final, &end_of_final);

	printf("\n");
	printf("#### Polynomial A ####");
	printf("\n");
	print_poly(start_of_first, end_of_first);
	printf("\n");

	printf("\n");
        printf("#### Polynomial B ####");
	printf("\n");
        print_poly(start_of_second, end_of_second);
        printf("\n");

	printf("\n");
        printf("#### Polynomial D ####");
	printf("\n");
	print_poly(start_of_final, end_of_final);
	printf("\n");

	return 0;
}
