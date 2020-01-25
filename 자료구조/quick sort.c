#include <stdio.h>


void SWAP(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int list[], int left, int right) {
	int pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {

		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);

		if (low < high) SWAP(&list[low], &list[high]);

		for (int i = 0; i < 10; i++)
			printf("%d ", list[i]);
		printf("\n피벗: %d \n", pivot);
	} while (low < high);

	//low>=high 이면,
	SWAP(&list[left], &list[high]);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void) {
	int arr[10] = { 12,10,5,11,2,7,13,8,300,0 };
	printf("\n----정렬전---\n");
	for (int i = 0; i<10; i++)
		printf("%d ", arr[i]);

	printf("\n");

	printf("<정렬 과정>\n");
	quick_sort(arr, 0, 9);

	printf("\n----정렬후---\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}