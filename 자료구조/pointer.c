#include <stdio.h>
main()
{
	int n, *np = NULL;//*->������, �ּҸ�����.
	int *pt = np;//�ּҿ� �ּ� ����.
	char c, *cp = &c;

	np = &n; //np�� n�� �ּҰ� ����ִ�
	*np = 10; //np �ּ� (n���ּ�) ���� 10����

	printf("np=%d n=%d pt=%d", *np,n,pt);
	return 0;
}