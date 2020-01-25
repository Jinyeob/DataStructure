#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

/*
<<�ǽ�>>
����� �̸��� ������ ������ ���ĵ� ����Ʈ�� �����ϴ� ���߿��Ḯ��Ʈ
*/

/* ��ǻ�Ͱ��а�_2015154007_������*/

typedef char element;
typedef struct person {
	element name[64];
	struct person *next;
	struct person *prev;
}person;

person *first, *last;

void init(); //����Ʈ�ʱ�ȭ
void dllsorted_insert(); //�Է�
void dlist_display(); //���

int main() {
	int a;
	init();

	for(;;) {
		puts("################");
		puts("1. �Է�");
		puts("2. ���");
		puts("3. ����  ");
		puts("################");

		scanf("%d", &a);  fflush(stdin); // ���ۺ��

		switch (a) {
		case 1:
			dllsorted_insert();
			break;
		case 2:
			dlist_display();
			break;
		case 3:
			return 0;
		default:
			puts("�߸� �Է��Ͽ���.");
			break;
		}
	}
	return 0;
}

void init() {
	//��� ����� ��ũ �ʵ���� �ڱ� �ڽ��� ����Ű���� �ʱ�ȭ
	first = (person*)malloc(sizeof(person));
	last = (person*)malloc(sizeof(person));

	first->next = last;
	first->prev = first;
	last->prev = first;
	last->next = last;
}

void dllsorted_insert() {
	person *tmp = first->next;
	person *node = (person*)malloc(sizeof(person)); // �� ���
	char name[10]; 

	printf("�̸� �Է�: ");
	scanf("%s", name);

	strcpy(node->name, name); //�� ��忡 �̸� ����

	if (first->next == last)  {
		first->next = node;
		node->prev = first;
		node->next = last;
		last->prev = node;
		return;
	}
	else {
		for(;;) {
			if (strcmp(tmp->name, node->name) > 0) {
				node->next = tmp;
				node->prev = tmp->prev;
				tmp->prev->next = node;
				tmp->prev = node;
				return;
			}

			if (tmp == last) {
				node->next = last;
				node->prev = last->prev;
				last->prev->next = node;
				last->prev = node;
				return;
			}
			tmp = tmp->next;
		}
	}
}

void dlist_display() {
	person *tmp = first->next;
	while (tmp != last) {
		printf(" %s \n", tmp->name);
		tmp = tmp->next;
	}
}