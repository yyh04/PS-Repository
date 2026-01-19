#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) { // 이차원 배열에서 검정색 사각형 부분은 모두 1값으로 바꿈 -> 마지막 배열에서 1의 개수만 카운트
	int N;
	int arr[100][100] = { 0, };
	int pnt[2]; // pnt[0]: 사각형 왼쪽 아래 점의 x좌표, pnt[1]: 사각형 왼쪽 아래 점의 y좌표
	int cnt = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &pnt[j]);
		}

		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[pnt[1] + j][pnt[0] + k] = 1; // 검정색 사각형 부분의 값을 모두 1로 교체
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}

	printf("%d", cnt);
	return 0;
}