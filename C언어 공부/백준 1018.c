#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int cnt = -1;
	int min = 32;
	int N, M;
	int changeWtoB1 = 0;
	int changeWtoB2 = 0;
	int changeBtoW1 = 0;
	int changeBtoW2 = 0;
	scanf("%d %d", &N, &M);

	int* num = (int*)calloc((M - 7) * (N - 7) * 2, sizeof(int));
	char** chess = (char**)calloc(N, sizeof(char*));
	for (int i = 0; i < N; i++) {
		*(chess + i) = (char*)calloc(M+1, sizeof(char));
		scanf("%s", chess[i]);
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((k + l) % 2 == 0 && chess[k + i][j + l] == 'W') { // 짝수에 B가 있어야 하는 경우
						changeWtoB1++;
					}
					if ((k + l) % 2 != 0 && chess[k + i][j + l] == 'B') {
						changeBtoW1++;
					}

					if ((k + l) % 2 == 0 && chess[k + i][j + l] == 'B') { // 짝수에 W가 있어야 하는 경우
						changeBtoW2++;
					}
					if ((k + l) % 2 != 0 && chess[k + i][j + l] == 'W') {
						changeBtoW2++;
					}
				}
			}
			cnt++;
			num[cnt] = changeWtoB1 + changeBtoW1;
			cnt++;
			num[cnt] = changeWtoB2 + changeBtoW2;
			changeWtoB1 = 0;
			changeBtoW1 = 0;
			changeWtoB2 = 0;
			changeBtoW2 = 0;
		}
	}

	for (int i = 0; i < (M - 7) * (N - 7) * 2; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}

	printf("%d", min);

	for (int i = 0; i < N; i++) {
		free(*(chess + i));
	}

	free(num);
	return 0;
}