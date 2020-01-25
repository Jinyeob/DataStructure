#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

//Return by a referred argument

void function1(char **);
void function2(char **);
void function3(char **);

int main()
{
	char *school = NULL;
	char *dept = NULL;
	char *name = NULL;

	function1(&school);
	function2(&dept);
	function3(&name);
	printf("%s \n%s \n%s \n", school, dept, name );
	return 0; //메모리 반납
}

void function1(char **a) { //&school
	*a = (char *)malloc(100*sizeof(char));
	strcpy(*a, "한국산업기술대학교");
}
void function2(char **b) { //&dept
	*b = (char *)malloc(100*sizeof(char));
	strcpy(*b, "컴퓨터 공학과");
}
void function3(char **c) { //&name
	*c = (char *)malloc(100*sizeof(char));
	strcpy(*c, "김진엽");
}