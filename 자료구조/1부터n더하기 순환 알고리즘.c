#include <stdio.h>

int sunhwan();

int main(void)
{
	int n;
	scanf_s("%d", &n);
	printf("=%d\n", sunhwan(n));
}

int sunhwan(int x)
{
	printf("%d+\n", x);
	if (x == 1) return 1;
	else return (x + sunhwan(x - 1));
	/*

	int sum = 0;
	for (int i = 1; i <= x; i++)
		sum += i;
	return x;
	*/
}
