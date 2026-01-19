#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int k = 1;

	for (int i = 1; i <= n; i++) {
		k *= i;
	}

	if (n == 0) {
		printf("1");
	}
	else {
		printf("%d", k);
	}

	return 0;
}