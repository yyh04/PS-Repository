#include <stdio.h>

int num = 5; // 원소의 개수
int arr[5] = { 3, 1, 4, 2, 5 };

void show();
void quickSort(int*, int, int);

int main(void) { // 메인 함수
	quickSort(arr, 0, num - 1);
	show();

	return 0;
}

void show() { // 배열 출력 함수
	for (int i = 0; i < 5; i++) {
		printf("%-2d", arr[i]);
	}
}

void quickSort(int* arr, int start, int end) { // 퀵정렬 알고리즘
	int pivot = start;
	int startUp = start + 1;
	int endDown = end;
	int temp = 0;

	if (start >= end) { // 부분집합에 원소가 한 개 있는 경우
		return;
	}

	while (startUp <= endDown) {
		while (startUp <= end && arr[startUp] <= arr[pivot]) { // arr[startUp} >= arr[pivot]인 경우는 내림차순
			startUp++;
		}
		while (endDown > start && arr[endDown] >= arr[pivot]) { // arr[endDown] <= arr[pivot]인 경우는 내림차순
			endDown--;
		}
		if (startUp > endDown) { // 엇갈린 경우
			temp = arr[endDown];
			arr[endDown] = arr[pivot];
			arr[pivot] = temp;
		}
		else { // 엇갈리지 않은 경우
			temp = arr[endDown];
			arr[endDown] = arr[startUp];
			arr[startUp] = temp;
		}
	}

	quickSort(arr, start, endDown - 1); // pivot 왼쪽 부분집합에서 실행
	quickSort(arr, endDown + 1, end); // pivot 오른쪽 부분집합에서 실행
}