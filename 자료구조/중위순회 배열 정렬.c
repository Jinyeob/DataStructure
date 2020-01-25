/*
���ڵ��� ��� �ִ� ���� Ž�� Ʈ���� ���� ��ȸ�ϸ� ���ĵ� ���ڰ� �������. 
�̸� �̿��Ͽ� �迭�� ��� �ִ� ���ڵ������Ľ�Ű�� �Լ��� �ۼ��Ͽ�����.
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
	int is_thread;
} TreeNode;

// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode *p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}
TreeNode *find_successor(TreeNode *p) {
	TreeNode *q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL)q = q->left;
	return q;
}
//������ȸ
void thread_inorder(TreeNode *t) {
	TreeNode *q;
	q = t;
	while (q->left != NULL) q = q->left;
	do
	{
		printf("%c", q->key);
		q = find_successor(q);
	} while (q != NULL);
}
void Inorder_Recursion(TreeNode * node){
	if (node == NULL)
		return;
	//���� ��� ����Լ� ����
	Inorder_Recursion(node->left);
	//�ڽ� ������ ���
	display(node->key);
	//������ ��� ����Լ� ����
	Inorder_Recursion(node->right);
}

// ��ȯ���� Ž�� �Լ�
TreeNode *search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
// �ݺ����� Ž�� �Լ�
TreeNode *search1(TreeNode *node, int key)
{
	while (node != NULL) {
		printf("%d ", node->key);
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; 	// Ž���� �������� ��� NULL ��ȯ
}

// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p�� �θ� ���, p�� �ڽ� ��� 
	TreeNode *n;	 // n�� ���ο� ���

	t = *root;
	p = NULL;
	// Ž���� ���� ���� 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// item�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;
	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}
// ���� �Լ�
void delete_node(TreeNode **root, int key) //key�� ������°�
{
	TreeNode *p, *child, *succ, *succ_p, *t;
	// p�� �θ���, t�� ������, succ�� �İ��ڳ��, succ_p�� �İ��ڳ���� �θ�

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}
	// �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// �θ��尡 ������ ��Ʈ
			*root = NULL;
	}
	// �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// �θ��带 �ڽĳ��� ���� 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	// �ΰ��� �ڽ��� ������ ���
	else {
		// *����* ����Ʈ������ �ļ��ڸ� ã�´�.
		succ_p = t; //�İ����� �θ� ���� ��忡 ����
		succ = t->left; //�����Ǵ� ����� ���� ����Ʈ��
						// �ļ��ڸ� ã�Ƽ� ��� ���������� �̵��Ѵ�.
		while (succ->right != NULL) {
			//(���ʼ���Ʈ��)���� ������ �ڽĸ�ũ�� ���� NULL�� ���������� ����
			succ_p = succ;
				succ = succ->right;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->right == succ) //
			succ_p->right = succ->left;
		else
			succ_p->left = succ->left;
		// �ļ��ڸ� ���� ���� �̵��Ѵ�.
		t->key = succ->key;
		t = succ;
	}
	printf("�����Ϸ��� key��: %d \n", key);

	/*	// �ΰ��� �ڽ��� ������ ���
	else {
	// *������* ����Ʈ������ �ļ��ڸ� ã�´�.
	succ_p = t;
	succ = t->right;
	// �ļ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
	while (succ->left != NULL) {
	succ_p = succ;
	succ = succ->left;
	}
	// �ļ����� �θ�� �ڽ��� ����
	if (succ_p->left == succ)
	succ_p->left = succ->right;
	else
	succ_p->right = succ->right;
	// �ļ��ڸ� ���� ���� �̵��Ѵ�.
	t->key = succ->key;
	t = succ;
	}
	*/
	free(t);
}

void main()
{
	TreeNode n1 = { 'K',NULL,NULL,1 };
	TreeNode n2 = { 'r',NULL,NULL,1 };
	TreeNode n3 = { 'o',&n1,&n2,0 };
	TreeNode n4 = { 'a',NULL,NULL,1 };
	TreeNode n5 = { 'O',NULL,NULL,0 };
	TreeNode n6 = { 'P',&n4,&n5,0 };
	TreeNode n7 = { 'e',&n3,&n6,0 };
	TreeNode *root = &n7;
		
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(root);

	/*
	display(root); printf("\n");

	display(root);
	*/
}
