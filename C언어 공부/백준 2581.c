#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int M, N = 0;

	scanf("%d %d", &M, &N);

	int* range = (int*)calloc((N - M + 1), sizeof(int));
	int* prime = (int*)calloc(N - M + 1, sizeof(int));
	int cnt_prime = 0;
	int p = 0;
	int sum = 0;

	for (int i = M; i <= N; i++) {
		int cnt = 0;
		int* divisor = (int*)calloc(N, sizeof(int));
		range[i - M] = i; // 해당 범위의 수를 넣음

		for (int j = 1; j <= range[i - M]; j++) {
			if (range[i - M] % j == 0) { // 약수 판별
				divisor[cnt] = j;
				cnt++;
			}
		}

		if (divisor[0] == 1 && divisor[1] == range[i - M]) { // 소수 판별
			prime[cnt_prime] = range[i - M];
			cnt_prime++;
		}

		free(divisor);
	}

	while (prime[p] != 0) { // 소수 합
		sum += prime[p];
		p++;
	}

	if (prime[0] == 0) { // 소수 없는 경우
		printf("-1");
	}
	else {
		printf("%d\n%d", sum, prime[0]);
	}

	free(prime);
	free(range);
	return 0;
}