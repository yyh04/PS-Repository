#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5] = { 0, };
	int temp;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++) { // 버블 정렬
		for (int j = 0; j < 4; j++) {
			if (arr[j] >= arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("%d\n", (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5);
	printf("%d", arr[2]);

	return 0;
}