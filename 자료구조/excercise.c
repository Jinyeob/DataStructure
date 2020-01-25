#include <stdio.h>

struct mystruct_tag {
	int a;
	int b;
	int c;
}object = { .c = 30,.a = 2 };

main() {
	printf("%d\n", object.c);
}
