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

char *function1()//�б� 
{ 
	char *s = NULL;
	s = (char *)malloc(30*sizeof(char));
	strcpy(s, "�ѱ����������б�");
	return s;
}

char *function2()// �а�
{
	char *d = NULL;
	d = (char *)malloc(30*sizeof(char));
	strcpy(d, "��ǻ�� ���а�");
	return d;
}

char *function3()//�̸�
{
	char *n = NULL;
	n = (char *)malloc(30*sizeof(char));
	strcpy(n, "������");
	return n;
}