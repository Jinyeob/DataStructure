#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
dlist_insert()�� ����Ͽ� ����� �̸��� ������ ������ ���ĵ� ����Ʈ�� �����ϴ� ���߿��Ḯ��Ʈ,
person *dllsorted_insert (person *list, person *bef, person *new)�� �����ϰ� �ϼ��Ͻÿ�.
*/

typedef struct address_t {
	char name[64];

	struct address_t *prev; //�������� �� �� �ִ�.
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
		fprintf(stderr, "���ϴ� �ൿ �Է�: \ni : �̸� �ֱ� \nd : �̸� ����� \ns : �̸� ����Ʈ ���� \nq : ������\n");

		switch (getchar()) {
		case 'i': {
			person *item;

			if (!(item = (person *)malloc(sizeof(person)))) {
				fprintf(stderr, "Error: DLL malloc in myfunc\n");
				return 0;
			}

			fprintf(stderr, "�̸� �Է�:");
			scanf("%s", item->name);

			first = dllsorted_insert(item, first);
			break;
		}
		case 'd': {
			person item;

			fprintf(stderr, "���� �̸� ���ﲨ��?:");
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

// ��� new_node�� ��� before�� ������ �����Ѵ�.
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
	new_node->prev = before;
	new_node->next = before->next;
	before->next->prev = new_node;
	before->next = new_node;
}

// ��� removed�� �����Ѵ�.
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
