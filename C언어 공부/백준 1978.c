#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n = 0;
	int num[1000] = { 0, };
	int cnt_prime = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++) {
		int divisor[1000] = { 0, };
		int cnt = 0;

		for (int j = 1; j <= 1000; j++) { // arr[j]의 약수를 divisor[cnt]에 오름차순으로 저장
			if (num[i] % j == 0) {
				divisor[cnt] = j;
				cnt++;
			}
			else if (num[i] == 0) {
				break;
			}
		}

		if (divisor[0] == 1 && divisor[1] == num[i]) {
			cnt_prime++;
		}
	}

	printf("%d", cnt_prime);
	
	return 0;
}