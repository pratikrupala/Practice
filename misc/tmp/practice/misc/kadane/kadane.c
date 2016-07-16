#include <stdio.h>
#include <stdlib.h>

int *find_sub_array(char *inp, int l)
{
	int temp_max = 0;
	int max = 0;
	int start = 0;
	int end = 0;
	int *conv = NULL;
	int i = 0;
	int *ret = NULL;
	int count = 0;

	conv = malloc(l * sizeof(int));
	if (!conv) {
		printf("Failed to allocate memory for temp array.\n");
		exit(EXIT_FAILURE);
	}

	ret = malloc(2 * sizeof(int));
	if (!ret) {
		printf("Failed to allocate memory for return array.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < l; i++) {
		if (inp[i] == '1')
			conv[i] = -1;
		else
			conv[i] = 1;
	}

/*
	printf("Converted arr:");
	for (i = 0; i < l; i++) {
		printf("%d", conv[i]);
	}
	printf("\n");
*/

	for (i = 0; i < l; i++) {
		if (conv[i] == -1)
			count++;
	}
	if (count == l)
		goto out;

	for (i = 0; i < l; i++) {
		temp_max += conv[i];
		if (temp_max <= 0) {
			temp_max = 0;
			start = i + 1;
		}

		if (temp_max > max) {
			max = temp_max;
			end = i;
		}
	}

	ret[0] = start + 1;
	ret[1] = end + 1;

	return ret;

out:
	ret[0] = 0;
	ret[1] = 0;

	return ret;
}

int main(void)
{
	int len = -1;
	char *arr = NULL;
	int *result = NULL;

	printf("Enter the length of the string: ");
	scanf("%d", &len);
	if (len < 1) {
		printf("Invalid length.\n");
		exit(EXIT_FAILURE);
	}

	arr = malloc(len * sizeof(char));
	if (!arr) {
		printf("Failed to allocate memory for string.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter your binary string: ");	
	scanf("%s", arr);

	printf("Your string: %s", arr);
	printf("\n");

	result = find_sub_array(arr, len);
	printf("Result: start = %d and end = %d\n", result[0], result[1]);

	return 0;
}
