#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *next;
} ListNode;

// ��带 �������� �����ϴ� ���α׷�
ListNode *create_node(element data, ListNode *next)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	new_node->data = data;
	new_node->next = next;
	return(new_node);
}

// phead: ����Ʈ�� ��� �������� ������
// node : ���Ե� ���
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

// phead: ����Ʈ�� ��� �������� ������
// node : ���Ե� ���
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

// ���� ���Ḯ��Ʈ���� �������� �����
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

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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