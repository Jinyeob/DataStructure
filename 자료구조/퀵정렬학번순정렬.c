#include <stdio.h> 
#include <stdlib.h> 

typedef struct score_tag {
	char title[32];
	char gpa[3];
}Score;

typedef struct student_tag {
	int id;
	char name;
	Score score;
}Student;


int compare(const void *A, const void *B)
{
	Student *ptA = (Student *)A;
	Student *ptB = (Student *)B;

	if (ptA->id < ptB->id) return -1;
	else if (ptA->id > ptB->id) return 1;
	else return 0;
}

int main()
{
	Student kpu_ce[10] = { {3,"��",50},{4,"��",30},{1,"��",90},{7,"��",35},{2,"��",47},{9,"��",77},{5,"��",12},{6,"��",10},{8,"��",56} };

	qsort((void*)kpu_ce, (size_t)10, sizeof(int), compare);
	printf("id�� ����\n");
	for (int i = 0; i<10; i++)
		printf("id: %d name: %s score: %d\n ", kpu_ce[i].id, kpu_ce[i].name, kpu_ce[i].score);

	return 0;
}