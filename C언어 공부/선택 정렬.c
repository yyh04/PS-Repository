#include <stdio.h>

int main(void) {
	int arr[10] = { 10, 5, 7, 8, 3, 4, 1, 9, 2, 6 };
	int temp = 0, min = 9999;

	for (int i = 0; i < 10; i++) {
		min = 9999;
		for (int j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				temp = j;
			}
		}
		arr[temp] = arr[i];
		arr[i] = min;
	}

	for (int i = 0; i < 10; i++) {
		printf("%-2d", arr[i]);
	}

	return 0;
}