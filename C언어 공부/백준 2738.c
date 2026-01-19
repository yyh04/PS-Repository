#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	int** arrA = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		*(arrA + i) = (int*)malloc(sizeof(int) * M);
	}

	int** arrB = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		*(arrB + i) = (int*)malloc(sizeof(int) * M);
	}

	int** arrSum = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		*(arrSum + i) = (int*)malloc(sizeof(int) * M);
	}


	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			scanf("%d ", &arrA[j][k]);
		}
	}

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			scanf("%d", &arrB[j][k]);
		}
	}

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			*(*(arrSum + j) + k) = *(*(arrA + j) + k) + *(*(arrB + j) + k);
			printf("%d ", *(*(arrSum + j) + k));
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		free(*(arrA + i));
		free(*(arrB + i));
		free(*(arrSum + i));
	}

	return 0;
}