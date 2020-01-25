
//선택정렬
void SelectionSort(int arr[], int MAX) {
	int i, j;
	int min, temp;
	for (i = 0; i<MAX - 1; i++) {
		min = i;
		for (j = i + 1; j<MAX; j++) {
			if ( arr[min] > arr[j] ) min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

//삽입정렬
void InsertSort (int arr[],int N ) {
	int temp;
	for (int i = 0; i < N; i++) {
		temp = arr[i];
		for (int j = i; j < 0; j--) {
			if (arr[j - 1] > temp) {
				arr[j] = arr[j - 1];
				if (j == 1) {
					arr[j - 1] = temp;
					break;
				}
			}
			else {
				arr[j] = temp;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}

//버블정렬
void BubbleSort(int data[],int N) { //N은 배열길이
	int i, j, temp;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N - (i + 1); j++) {
			if (data[j] > data[j + 1]) {
				// 자리교환
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}
}