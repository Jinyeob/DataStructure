#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

/*
<<실습>>
사람의 이름을 사전적 순서로 정렬된 리스트를 유지하는 이중연결리스트
*/

/* 컴퓨터공학과_2015154007_김진엽*/

typedef char element;
typedef struct person {
	element name[64];
	struct person *next;
	struct person *prev;
}person;

person *first, *last;

void init(); //리스트초기화
void dllsorted_insert(); //입력
void dlist_display(); //출력

int main() {
	int a;
	init();

	for(;;) {
		puts("################");
		puts("1. 입력");
		puts("2. 출력");
		puts("3. 종료  ");
		puts("################");

		scanf("%d", &a);  fflush(stdin); // 버퍼비움

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
			puts("잘못 입력하였음.");
			break;
		}
	}
	return 0;
}

void init() {
	//헤더 노드의 링크 필드들이 자기 자신을 가리키도록 초기화
	first = (person*)malloc(sizeof(person));
	last = (person*)malloc(sizeof(person));

	first->next = last;
	first->prev = first;
	last->prev = first;
	last->next = last;
}

void dllsorted_insert() {
	person *tmp = first->next;
	person *node = (person*)malloc(sizeof(person)); // 새 노드
	char name[10]; 

	printf("이름 입력: ");
	scanf("%s", name);

	strcpy(node->name, name); //새 노드에 이름 복사

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