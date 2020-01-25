#include <stdio.h>
main()
{
	int n, *np = NULL;//*->포인터, 주소를담음.
	int *pt = np;//주소에 주소 대입.
	char c, *cp = &c;

	np = &n; //np에 n의 주소가 담겨있다
	*np = 10; //np 주소 (n의주소) 가서 10대입

	printf("np=%d n=%d pt=%d", *np,n,pt);
	return 0;
}