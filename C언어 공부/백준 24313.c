#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a1, a0, c, n0;
	scanf("%d %d %d %d", &a1, &a0, &c, &n0);

	if (a1 * n0 + a0 <= c * n0 && a1 <= c) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}