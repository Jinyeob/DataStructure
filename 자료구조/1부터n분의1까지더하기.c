#include <stdio.h>

double division();

int main(void)
{
	int n;
	scanf_s("%d", &n); //�Է�
	printf("=%lf\n", division(n)); //���
	return 0;
}

double division(int x)
{
	printf("%lf+\n", x);
	if (x == 1) return 1; //Ż��
	else return (1/x+sunwhan(x-1)); //��ȯ
}