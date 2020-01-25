#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

//Return by return type of struct*

char *function1();
char *function2();
char *function3();

int main()
{
	char *school = NULL;
	char *dept = NULL;
	char *name = NULL;

	school = function1();
	dept = function2();
	name = function3();
	printf("%s \n%s \n%s \n", school,dept, name);
	return 0;
}

char *function1()//학교 
{ 
	char *s = NULL;
	s = (char *)malloc(30*sizeof(char));
	strcpy(s, "한국산업기술대학교");
	return s;
}

char *function2()// 학과
{
	char *d = NULL;
	d = (char *)malloc(30*sizeof(char));
	strcpy(d, "컴퓨터 공학과");
	return d;
}

char *function3()//이름
{
	char *n = NULL;
	n = (char *)malloc(30*sizeof(char));
	strcpy(n, "김진엽");
	return n;
}