#include <stdio.h>

double ai(double m,double n)
{
int stack[100000];
stack[0] = m;
stack[1] = n;

int t = 1;

do
{
double c = c + 1;
if (stack[t - 1] == 0)
{
m = 0;
t = t - 1;
stack[t] = stack[t + 1] + 1;
}
else if (stack[t] == 0)
{
n = 0;
stack[t] = 1;
stack[t - 1] = stack[t - 1] - 1;
}
else
{
stack[t + 1] = stack[t] - 1;
stack[t] = stack[t - 1];
stack[t - 1] = stack[t - 1] - 1;
t = t + 1;
}
}
while(t != 0);
return stack[0];

}

int main(void)
{
	int m = 0, n = 0, r = 0;

	printf("Please enter the value of m:");
	scanf("%d", &m);

	printf("Please enter the value of n:");
        scanf("%d", &n);

	printf("You have entered m: %d and n: %d\n", m, n);

	r = ai(m, n);

	printf("Result of Akermann's function: %d\n", r);

	return 0;
}
