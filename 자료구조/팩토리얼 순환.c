#include <stdio.h>

int factorial(int n) {
	if (n <= 1) return 1;

	else return n * factorial(n - 1);
}

int main(void) {
	int n;
	printf("n! �Է�:");
	scanf_s("%d", &n);

	printf("%d",factorial(n));

	return 0;
}