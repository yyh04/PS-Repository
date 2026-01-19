#define _CRT_SEUCRE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int N;
	int sumHealth = 0;
	int sumHappiness = 0;
	int max = 0;
	int arr[2][21] = { 0, };

	scanf("%d", &N);

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < N; j++) {

			scanf("%d", arr[i][j]);

		}

	}

	for (int i = N; i > 0; i--) {

		for (int j = i; j > 0; j--) {

			sumHealth += arr[0][j];
			sumHappiness += arr[1][j];

		}

	}

	return 0;

}