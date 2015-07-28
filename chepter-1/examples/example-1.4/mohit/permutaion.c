#include <stdio.h>
#include <string.h>
#include "../../example-1.1/mohit/functions.h"

int main()
{
	char arr[] = "abc";
	int n = strlen(arr)/sizeof(char);
	permutaion(arr, 0, n-1);
	printf("\n");
	return SUCESS;
}
