#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	int cnt3 = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char arr[100];
		scanf("%s", arr);
		int len = strlen(arr);
		char cmp[100] = { 0, };
		cmp[0] = arr[0];
		int cnt = 0;
		int cnt2 = 0;

		for (int j = 0; j < len; j++) {
			if (arr[j] != arr[j + 1]) {
				cnt++;
				cmp[cnt] = arr[j + 1];
			}
		}

		int len2 = strlen(cmp);

		for (int j = 0; j < len2; j++) {
			for (int k = j + 1; k < len2; k++) {
				if (cmp[j] == cmp[k] && cnt2 != 1) {
					cnt2++;
				}
			}
		}

		if (cnt2 == 1) {
			cnt3++;
		}
		cnt = 0;
		cnt2 = 0;
	}

	printf("%d", N - cnt3);

	return 0;
}