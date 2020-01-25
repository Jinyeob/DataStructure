#include <stdio.h>

struct person {
	char name[10];
	int age;
	float height;
};
typedef struct person person;

int compare(person a, person b)
{
	if(a.age > b.age) return 1;
	else if (a.age == b.age) return 0;
	else return -1;
}

main() {
	person a, b;
	a.age = 30;
	b.age = 20;
	if (compare(a, b))
		printf("a>b");
}