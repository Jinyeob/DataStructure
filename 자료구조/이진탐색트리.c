#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;
// 이진 탐색 트리 출력 함수
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
// 순환적인 탐색 함수
TreeNode *search(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
// 반복적인 탐색 함수
TreeNode *search1(TreeNode *node, int key)
{
	while (node != NULL) {
		printf("%d ", node->key);
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; 	// 탐색에 실패했을 경우 NULL 반환
}

// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p는 부모 노드, p는 자식 노드 
	TreeNode *n;	 // n은 새로운 노드

	t = *root;
	p = NULL;
	// 탐색을 먼저 수행 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// item이 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}
// 삭제 함수
void delete_node(TreeNode **root, int key) //key는 지우려는거
{
	TreeNode *p, *child, *succ, *succ_p, *t; 
	// p는 부모노드, t는 현재노드, succ는 후계자노드, succ_p는 후계자노드의 부모

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}
	// 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// 부모노드가 없으면 루트
			*root = NULL;
	}
	// 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// 부모노드를 자식노드와 연결 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	// 두개의 자식을 가지는 경우
	else {		
				// *왼쪽* 서브트리에서 후속자를 찾는다.
		succ_p = t; //후계자의 부모를 현재 노드에 연결
		succ = t->left; //삭제되는 노드의 왼쪽 서브트리
		// 후속자를 찾아서 계속 오른쪽으로 이동한다.
		while (succ->right != NULL) { 
		//(왼쪽서브트리)에서 오른쪽 자식링크를 통해 NULL을 만날때까지 진행
			succ_p = succ;
			succ = succ->right;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->right == succ) //
			succ_p->right = succ->left; 
		else
			succ_p->left = succ->left;
		// 후속자를 현재 노드로 이동한다.
		t->key = succ->key;
		t = succ;
	}
	printf("제거하려는 key값: %d \n", key);

/*	// 두개의 자식을 가지는 경우
	else {		
				// *오른쪽* 서브트리에서 후속자를 찾는다.
		succ_p = t;
		succ = t->right;
		// 후속자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// 후속자를 현재 노드로 이동한다.
		t->key = succ->key;
		t = succ;
	}
*/
	free(t);
}

void main()
{
	TreeNode *root = NULL;

	// 삽입
	insert_node(&root, 35);
	insert_node(&root, 18);
	insert_node(&root, 68);
	insert_node(&root, 99);
	insert_node(&root, 7);
	insert_node(&root, 26);
	insert_node(&root, 3);
	insert_node(&root, 12);
	insert_node(&root, 22);
	insert_node(&root, 30);


	display(root); printf("\n");

	delete_node(&root, 18);
	display(root);
}
