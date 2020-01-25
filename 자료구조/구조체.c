#include <stdio.h>
#include <math.h>

typedef struct point_tag{
	int x;
	int y;
}point;


int main(void)
{
	point P1 = { 1.0, 2.0 };
	point P2 = { 9.0, 8.0 };
	printf("두 점 사이 거리:%d", get_distance(P1,P2));
	return 0;
}

int get_distance(point p1, point p2)
{
	int a, b;
	double result;
	a = (p2.x - p1.x)*(p2.x - p1.x);
	b =	(p2.y - p1.y)*(p2.y - p1.y);
	result = sqrt(a + b);
	return  result;
}