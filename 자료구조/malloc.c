main()
{
	int *pi;
	pi = (int*)malloc(sizeof(int));
 /*
 동적 메모리 사용
*/
		free(pi); //동적 메모리 반납
}

//전형적인 동적 메모리 할당 코드
