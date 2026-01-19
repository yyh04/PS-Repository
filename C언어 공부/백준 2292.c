#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N = 0;
	int range = 1;
	int cnt = 0;

	scanf("%d", & N);

	for (int i = 0; i < 18258; i++) {
		range += (6 * i);
		cnt++;

		if (range >= N) {
			printf("%d", cnt);
			break;
		}

	}
	return 0;
}