#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
dlist_insert()를 대신하여 사람의 이름을 사전적 순서로 정렬된 리스트를 유지하는 이중연결리스트,
person *dllsorted_insert (person *list, person *bef, person *new)을 구현하고 완성하시오.
*/

typedef struct address_t {
	char name[64];

	struct address_t *prev; //더블인지 알 수 있다.
	struct address_t *next; 
} person;

person *first, *last;

person *dllsorted_insert(person *i, person *top);
person *dlist_insert(person *i);
void dlist_display(person *i);
void dll_show_list(person *first);
void dlist_delete(char  *name);
person *person_find(char *name);


person *dllsorted_insert(person *i, person *top)
{
	person *old, *p;

	if (last == NULL) {		// first element in list
		i->next = NULL;
		i->prev = NULL;
		last = i;
		return i;
	}

	p = top;
	old = NULL;

	while (p) {
		if (atol(p->name) < atol(i->name)) { // sorting order: "the smaller the closer to first"
			old = p;
			p = p->next;
		}
		else {
			if (p->prev) {
				p->prev->next = i;
				i->next = p;
				i->prev = p->prev;
				p->prev = i;
				return top;
			}
			i->next = p;		// new first element
			i->prev = NULL;
			p->prev = i;
			return i;
		}
	}
	old->next = i;					// put on end
	i->next = NULL;
	i->prev = old;
	last = i;

	return first;
}

person *dlist_insert(person *i) {
	if (last == NULL) {
		last = i;		// first item in list
		return i;
	}
	else last->next = i;

	i->next = NULL;
	i->prev = last;
	last = i;

	return first;
}
person *person_find(char *name)
{
	person *i;

	i = first;

	while (i) {
		if (!strcmp(name, i->name))
			return i;
		i = i->next;		// get next person list
	}
	return NULL;			// not found
}
void dlist_delete(char  *name) {
	person *i;

	i = person_find(name);
	if (i) {

		/* ******* do here any job related the list ******** */

		if (first == i) {
			first = i->next;
			if (first) first->prev = NULL;
			else last = NULL;
		}
		else {
			i->prev->next = i->next;
			if (i != last)
				i->next->prev = i->prev;
			else
				last = i->prev;
		}
		free(i);		// return memory to system
	}
}
void dlist_display(person *i) {

	fprintf(stderr, "%s\n", i->name);
}

void dll_show_list(person *first)
{
	while (first) {
		dlist_display(first);
		first = first->next;
	}
}


int main(int argc, char *argv[]) {
	/* Initialization  */
	first = last = NULL;

	/* networking & gathering of session data */
	for (;;) {
		fprintf(stderr, "원하는 행동 입력: \ni : 이름 넣기 \nd : 이름 지우기 \ns : 이름 리스트 보기 \nq : 나가기\n");

		switch (getchar()) {
		case 'i': {
			person *item;

			if (!(item = (person *)malloc(sizeof(person)))) {
				fprintf(stderr, "Error: DLL malloc in myfunc\n");
				return 0;
			}

			fprintf(stderr, "이름 입력:");
			scanf("%s", item->name);

			first = dllsorted_insert(item, first);
			break;
		}
		case 'd': {
			person item;

			fprintf(stderr, "무슨 이름 지울꺼냐?:");
			scanf("%s", item.name);
			dlist_delete(item.name);
			break;
		}
		case 's':
			dll_show_list(first);
			break;
		case 'q':
			return 0;
		default:
			fprintf(stderr, "typed wrong choice.\n");
		}
		continue;
	}

	return 0;
}


/*
typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *prev;
	struct DlistNode *next;
} DlistNode;

// 노드 new_node를 노드 before의 다음에 삽입한다.
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
	new_node->prev = before;
	new_node->next = before->next;
	before->next->prev = new_node;
	before->next = new_node;
}

// 노드 removed를 삭제한다.
void dremove_node(DlistNode *phead_node, DlistNode *removed)
{
	if (removed == phead_node) free(removed);
	else {
		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		free(removed);
	}
}
*/
