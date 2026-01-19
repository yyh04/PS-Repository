#include <stdio.h>

int checkSort(); // 선택 정렬
int bubbleSort(); // 버블 정렬
int insertSort(); // 삽입 정렬
int quickSort(); // 퀵 정렬

int main(void) {
	quickSort();
	return 0;
}

int checkSort(void) {
	int num = 3;
	int arr[3] = { 0, };
	int min = 1000001;

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (arr[j] < min) {
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
			}
		}
		min = 1000001;
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

int bubbleSort(void) {
	int num = 3;
	int arr[3] = { 0, };
	int temp;

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}


int insertSort(void) {
	int num = 3;
	int arr[3] = { 0, };
	int temp;

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < 2; i++) {
		int j = i;
		while (j >= 0 && arr[j] >= arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

int quickSort(void) {
	int num = 3;
	int arr[3] = { 0, };
	int temp;


	for (int i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	int start = arr[0];
	int end = arr[2];
	int pivot = start;
	int startUp = start + 1, endDown = end;

	if (start >= end) {
		return;
	}

	while (startUp <= endDown) {
		while (startUp <= end && arr[startUp] <= arr[pivot]) {
			startUp++;
		}
		while (endDown > start && arr[endDown] >= arr[pivot]) {
			endDown--;
		}
		if (startUp >= endDown) {
			temp = arr[endDown];
			arr[endDown] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[startUp];
			arr[startUp] = arr[endDown];
			arr[endDown] = arr[startUp];
		}
	}


	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}