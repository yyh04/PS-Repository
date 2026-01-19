#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) { // 카운팅 정렬
	int n;
	scanf("%d", &n);
	int i, k;

	int num;
	int idx[100000] = { 0, };

	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		idx[num]++;
	}

	for (i = 0; i < 100000; i++) {
		k = 0;
		while (k < idx[i]) {
			printf("%d\n", i);
			k++;
		}
	}

	return 0;
}