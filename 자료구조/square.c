#include <stdio.h>
double square();
int main(void)
{
	double a;
	int b;

	scanf_s("%lf %d", &a, &b);
	printf("%lf \n", square(a, b));

	return 0;
}

double square(double x, int n) //xÀÇ nÁ¦°ö
{
	int i;
	double r = 1.0;

	for (i = 0; i < n; i++)
		r = r * x;

	return (r);
}