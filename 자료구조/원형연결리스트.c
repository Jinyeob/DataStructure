#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *next;
} ListNode;

// 노드를 동적으로 생성하는 프로그램
ListNode *create_node(element data, ListNode *next)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->next = next;
	return(new_node);
}

// phead: 리스트의 헤드 포인터의 포인터
// node : 삽입될 노드
void insert_first(ListNode **phead, ListNode *node)
{
	if (*phead == NULL) {
		*phead = node;
		node->next = node;
	}
	else {
		node->next = (*phead)->next;
		(*phead)->next = node;
	}
}

// phead: 리스트의 헤드 포인터의 포인터
// node : 삽입될 노드
void insert_last(ListNode **phead, ListNode *node)
{
	if (*phead == NULL) {
		*phead = node;
		node->next = node;
	}
	else {
		node->next = (*phead)->next;
		(*phead)->next = node;
		*phead = node;
	}
}

// 원형 연결리스트내의 아이템을 출력함
void display(ListNode *head)
{
	ListNode *p;
	if (head == NULL) return;
	else head = head->next;

	printf("( ");
	p = head;
	do {
		printf("%d", p->data);
		p = p->next;
		if (p != head) printf(", ");
	} while (p != head);
	printf(") \n");
}

// 원형 연결 리스트 테스트 프로그램
int main()
{
	ListNode *list = NULL;

	insert_first(&list, create_node(10, NULL));
	display(list);
	// after insert list = ( 10 )
	insert_first(&list, create_node(20, NULL));
	display(list);
	//    // after insert list = ( 20, 10 )
	insert_first(&list, create_node(30, NULL));
	// after insert list = ( 20, 10, 30 )
	display(list);

	return 1;
}