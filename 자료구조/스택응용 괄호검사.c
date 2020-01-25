#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
	char data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(char item) { 
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}
char pop() {
	char item;
	stackNode* temp = top;
	if (top == NULL) {
		printf("Stack is empty \n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

char peek() { //���� ����Ʈ ������ top ���� �˻� ����
	char item;
	if (top == NULL) {
		printf("Stack is empty \n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}

void			