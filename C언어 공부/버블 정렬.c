#include <stdio.h>

int main(void) {
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	int min = 9999, temp = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (arr[j + 1] < arr[j]) {
				min = arr[j + 1];
				temp = arr[j];
				arr[j] = min;
				arr[j + 1] = temp;
			}
		}
		min = 9999;
	}

	for (int i = 0; i < 10; i++) {
		printf("%-2d", arr[i]);
	}

	return 0;
}