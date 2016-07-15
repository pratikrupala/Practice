#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

typedef struct {
	int expon;
	float coeff;
} polynomial;
polynomial list[MAX_TERMS];
int avail = 0;

void read_poly(void)
{
	printf("Keep entering polynomial terms and enter -1 for exponent to finish.\n");

	while (1) {
		if (avail >= (MAX_TERMS - 1)) {
			fprintf(stderr, "Polynomial array out of space.\n");
			exit(EXIT_FAILURE);
		}

		printf("Exponent:");
		scanf("%d", &list[avail].expon);

		if (list[avail].expon < 0) {
			break;
		}

		printf("Coefficient:");
		scanf("%f", &list[avail].coeff);

		avail++;
	}
}

void print_poly(int start, int end)
{
	int i;

	printf("%.2f", list[start].coeff);
	printf("x^%d", list[start].expon);

	for (i = start + 1; i <=end; i++) {
		printf("+ %.2f", list[i].coeff);
		printf("x^%d", list[i].expon);
	}
	printf("\n");
}
/*
int calc_temp_term(int val, int expon)
{
	int i;
	int ret = 1;

	for (i = expon; i > 0; i--) {
		ret *= val;
	}

	return ret;
}
*/
void poly_attach(int coeff, int expon)
{
	if (avail >= (MAX_TERMS - 1)) {
		fprintf(stderr, "No space left on polynomial array.");
		exit(EXIT_FAILURE);
	}

	list[avail].coeff = coeff;
	list[avail++].expon = expon;
}

void calc_temp_terms(int start, int end, int val, int *terms_start, 
			int *terms_end)
{
	int i, pivot = -1, limit = -1;
	int ret = 1;
	int track = end;

	limit = list[start].expon;
	pivot = list[track--].expon;

	*terms_start = avail;
	for (i = 1; i <= limit; i++) {
		ret *= val;
		if (i == pivot) {
			poly_attach(ret, 0);
			pivot = list[track--].expon;
		}
	}
	*terms_end = avail - 1;
}

void eval(int start, int end, int value)
{
	int terms_start;
	int terms_end;
	int i, j, k;
	float result = 0;

/*
	for (i = start; i <= end; i++) {
		temp_term = calc_temp_term(value, list[i].expon);
		poly_attach(temp_term, 0);
	}
*/
	calc_temp_terms(start, end, value, &terms_start, &terms_end);

	for (i = terms_end, j = 1, k = start; 
			i >= terms_start && k <= end; i--, j++, k++) {
//		printf("Temp term for %d: %.2f\n", j, list[i].coeff);
		result += list[i].coeff * list[k].coeff;
	}

	printf("\n\tFinal result of evaluation: %.2f\n", result);
}

int main(void)
{
	int first_start = 0;
	int first_end = 0;
	int val = -1;

	printf("Enter the first polynomial:\n");
	read_poly();
	first_end = avail - 1;

	printf("\n");
	printf("Polynomial A:\n");
	print_poly(first_start, first_end);

	printf("\n");
	printf("Print the value of variable for evaluation:");
	scanf("%d", &val);
	eval(first_start, first_end, val);

	return 0;
}
