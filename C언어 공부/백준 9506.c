#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	while (1) { // 무한 반복
		int n = 0, cnt = 0, sum = 0;

		scanf("%d", &n);

		if (n == -1) { // 입력이 -1인 경우 종료
			break;
		}

		int* arr = (int*)calloc(n, sizeof(int));

		for (int i = 1; i < n; i++) {
			if (n % i == 0) { // 약수를 오름차순으로 배열에 저장
				arr[cnt] = i;
				cnt++;
			}
		}

		for (int i = 0; i < cnt + 1; i++) {
			sum += arr[i];
		}

		if (sum == n) { //	완전수인 경우
			printf("%d = 1 ", n);

			for (int i = 1; i < cnt; i++) {
				printf("+ %d ", arr[i]);
			}

			printf("\n");
		}
		else if (sum != n) {
			printf("%d is NOT perfect.\n", n);
		}

		free(arr);
	}

	return 0;
}