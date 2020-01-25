#include <stdio.h>

double division();

int main(void)
{
	int n;
	scanf_s("%d", &n); //입력
	printf("=%lf\n", division(n)); //출력
	return 0;
}

double division(int x)
{
	printf("%lf+\n", x);
	if (x == 1) return 1; //탈출
	else return (1/x+sunwhan(x-1)); //순환
}