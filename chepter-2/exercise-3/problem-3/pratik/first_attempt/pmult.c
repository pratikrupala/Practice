#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) ((x) < (y)? -1 : ((x) == (y)? 0 : 1))
#define MAX_TERMS 50

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial list[MAX_TERMS];
int avail = 0;

void read_poly(void)
{
	printf("Keep entering polynomial terms and enter -1 for exponent at the"
	       " end.\n");

	while(1) {
		if (avail >= MAX_TERMS) {
        	        fprintf(stderr, "Polynomial array out of space...");
                	exit(EXIT_FAILURE);
	        }
		printf("Exponent: ");
		scanf("%d", &list[avail].expon);
		if (list[avail].expon < 0) {
			break;
		}

		printf("Coefficient: ");
		scanf("%f", &list[avail].coef);

		avail++;
	}

}

void print_poly(int start, int end)
{
	int i;

	printf("%.2fx^%d", list[start].coef, list[start].expon);

	for (i = (start + 1); i <= end; i++) {
		if (list[i].expon != 0)
			printf("+ %.2fx^%d", list[i].coef, list[i].expon);
		else
			printf("+ %.2f", list[i].coef);
	}
	
	printf("\n");
}

void poly_attach(int expon, int coef)
{

	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Polynomial array out of space...");
		exit(EXIT_FAILURE);
	}
	
	list[avail].expon = expon;
	list[avail++].coef = coef;
}

void padd(int first, int second, int third, int forth, int *rstart, int *rend)
{
	int coefficient = 0;
	*rstart = avail;
	while (first <= second && third <= forth) {
		switch (COMPARE(list[first].expon, list[third].expon)) {
		case -1:
			/* A is less than B.*/
			poly_attach(list[third].expon, list[third].coef);
			third++;
			break;

		case 0:
			/* A is equal to B.*/
			coefficient = list[first].coef + list[third].coef;
			poly_attach(list[first].expon, coefficient);
			first++;
			third++;
			break;

		case 1:
			/* A is greater than B.*/
			poly_attach(list[first].expon, list[first].coef);
			first++;
			break;
		}
	}

	for (; first <= second; first++) {
		poly_attach(list[first].expon, list[first].coef);
	}

	for (; third <= forth; third++) {
		poly_attach(list[third].expon, list[third].coef);
	}

	*rend = avail - 1;
}

void term_mult(int expon, int  coef, int start, int end, int *tstart, int *tend)
{
	int new_coef, new_expon;
	int i;

	*tstart = avail;

	for (i = start; i <= end; i++) {
		new_coef = coef * list[i].coef;
		new_expon = expon + list[i].expon;

		if (new_coef > 0)
			poly_attach(new_expon, new_coef);
		else
			continue;
	}
	*tend = avail - 1;

}

void pmult(int first, int second, int third, int forth, int *rstart, int *rend)
{
	int first_total_terms = second - first + 1;
	int second_total_terms = forth - third + 1;
	int pivot_start = 0;
	int pivot_end = 0;
	int non_pivot_start = 0;
	int non_pivot_end = 0;
	int latest_start = 0;
	int latest_end = 0;
	int *positions, len;
	int i, j;

	if (first_total_terms < second_total_terms) {
		pivot_start = first;
		pivot_end = second;
		non_pivot_start = third;
		non_pivot_end = forth;
	} else {
		pivot_start = third;
                pivot_end = forth;
                non_pivot_start = first;
                non_pivot_end = second;
	}

	len = pivot_end - pivot_start + 1;
	positions = malloc(len * 2);

	for (i = pivot_start, j = 0; i <= pivot_end; i++, j = j + 2) {
		term_mult(list[i].expon, list[i].coef, non_pivot_start, non_pivot_end,
				 (positions + j), (positions + j + 1));
	}
/* Only for debugging	
	for (i = 0, j = 0; i < (len * 2); i += 2, j++) {
		printf("Intermediate polynomial %d:\n", j);
		print_poly(*(positions + i), *(positions + i + 1));
	}
*/
	if (len > 1) {
		for (i = 0; i < (len * 2); i += 4) {
			if (i == 0) {
				pivot_start = *(positions + i);
	                	pivot_end = *(positions + i + 1);
        		        non_pivot_start = *(positions + i + 2);
	        	        non_pivot_end = *(positions + i + 3);
			} else {
				pivot_start = *(positions + i);
                                pivot_end = *(positions + i + 1);
				non_pivot_start = latest_start;
				non_pivot_end = latest_end;
				latest_start = 0;
				latest_end = 0;
			}

			padd(pivot_start, pivot_end, non_pivot_start, non_pivot_end, 
				&latest_start, &latest_end);
		}
		*rstart = latest_start;
		*rend = latest_end;
	} else {
		*rstart = *(positions);
		*rend = *(positions + 1);
	}
	
}

int main(void)
{
	int start_of_first = 0;
	int end_of_first = 0;
	int start_of_second = 0;
	int end_of_second = 0;
	int start_of_result = 0;
	int end_of_result = 0;

	printf("Enter polynomial A:\n");
	read_poly();
	end_of_first = avail - 1;

	printf("\n");
	start_of_second = avail;
	printf("Enter polynomial B:\n");
	read_poly();
	end_of_second = avail - 1;

	printf("\n");
	printf("Polynomial A:\n");
	print_poly(start_of_first, end_of_first);
	printf("\n");

	printf("\n");
        printf("Polynomial B:\n");
        print_poly(start_of_second, end_of_second);
        printf("\n");
	
	padd(start_of_first, end_of_first, start_of_second, end_of_second,
		&start_of_result, &end_of_result);
	printf("Result of addition:\n");
	print_poly(start_of_result, end_of_result);

        printf("\n");
	printf("Result of multiplication:\n");
	pmult(start_of_first, end_of_first, start_of_second, end_of_second,
		&start_of_result, &end_of_result);
	printf("\n");
	printf("Final result:\n");
	print_poly(start_of_result, end_of_result);
	printf("\n");
	return 0;
}
