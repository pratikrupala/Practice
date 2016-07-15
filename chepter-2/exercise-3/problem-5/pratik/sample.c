Explanation:
In the below function, case 0 of switch statement will never be executed as both the input polynomials do not have terms with  common exponent. The reason behind this is one of them is polynomial with terms having only even exponentials and other one having only odd exponentials. So, only case -1 and case 1 will be executed. The case -1 will be executed only for polynomial B and case 1 will be executed only for polynomial A. The case -1 will be executed (2n + 1)/2 times and case 1 will be executed for n times. So for case -1 value of count would be (2n + 1) * 3/2 and for case 1 it would be 3n. Apart from switch case, forst for loop will be executed once to add one last item of the even terms polynomials and second for loop will not be executed. Rest of the function steps would be common. So total step count for padd function would be ((2n + 1) * 3/2) + 3n + 10.

void padd(int first_start, int first_end, int second_start, int second_end, int *result_start, int *result_end)
{
	float coef = 0;		count++;
	*result_start = avail;	count++;

	while (first_start <= first_end && second_start <= second_end) {
		count++;
		switch (COMPARE(list[first_start].expon,
				list[second_start].expon)) {
		count++;
		case -1:
			poly_attach(list[second_start].coef,
					list[second_first].expon);
			count++;
			second_start++;		count++;
			break;
			count++;
		case 0:
			coef = list[first_start].coef + list[second_start].coef;
			count++;
			first_start++;
			count++;
			second_start++;
			count++;
			break;
			count++;

		case 1:
			poly_attach(list[first_start].coef,
					list[first_start].expon);
			count++;
			first_start++;
			count++;
			break;
			count++;
		}
		count++;
	}
	count++;

	for (; fisrt_start <= first_end; first_start++) {
		count++;
		poly_attach(list[first_start].coef, list[first_start].expon);
		count++;
                first_start++;
		count++;
	}
	count++;

	for (; second_start <= second_end; second_start++) {
		count++;
		poly_attach(list[second_start].coef,
				list[second_first].expon);
		count++;
                second_start++;
		count++;
	}
		count++;
}
