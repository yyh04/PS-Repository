#include <stdio.h>

int main(void) {
	int temp = 0;
	int arr[10] = { 1, 10, 8, 7, 6, 5, 3, 2, 4, 9 };

	for (int i = 0; i < 9; i++) {
		int j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%-2d", arr[i]);
	}

	return 0;
}