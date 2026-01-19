#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, B;
	scanf("%d %d", &N, &B);

	int quo = N;
	int rem = 0;
	int cnt = 30;
	char arr[30] = { 0, };
	char arr2[30] = { 0, };

	while (quo != 0) {
		cnt--;
		rem = quo % B;
		quo /= B;
		if (0 <= rem && rem <= 9) {
			arr[cnt] = rem + 48;
		}
		else if (10 <= rem && rem <= 35) {
			arr[cnt] = rem + 55;
		}
	}

	cnt--;

	if (0 <= quo && quo <= 9) {
		arr[cnt] = quo + 48;
	}
	else if (10 <= quo && quo <= 35) {
		arr[cnt] = quo + 55;
	}

	for (int i = 0; i < 30 - cnt - 1; i++) {
		arr2[i] = arr[cnt + i + 1];
	}

	printf("%s", arr2);
	return 0;
}