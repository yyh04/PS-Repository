#include <stdio.h>
int main(void) {
	int N;
	scanf_s("%d", &N);

	int arr[1000] = { 0, };
	int temp;

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (arr[j] >= arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}