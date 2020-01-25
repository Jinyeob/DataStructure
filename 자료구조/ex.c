#include <stdio.h>

void function(struct point *call);

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p = { 10,20 };
	function(&p);
	return 0;
}

void function(struct point *call)
{
	printf("%d %d\n", call->x, (*call).y);
}