#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int i;

	for (i = 1; i < 1000000; i++) {
		int num = 0;
		if (i < 10) {
			num = 2 * i;
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
		else if (10 <= i && i < 100) {
			num = i + (i % 10) + (i / 10);
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
		else if (100 <= i && i < 1000) {
			num = i + (i % 10) + ((i % 100 - i % 10) / 10) + (i / 100);
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
		else if (1000 <= i && i < 10000) {
			num = i + (i % 10) + ((i % 100 - i % 10) / 10) + ((i % 1000 - i % 100) / 100) + (i / 1000);
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
		else if (10000 <= i && i < 100000) {
			num = i + (i % 10) + ((i % 100 - i % 10) / 10) + ((i % 1000 - i % 100) / 100) + ((i % 10000 - i % 1000) / 1000) + (i / 10000);
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
		else if (100000 <= i && i < 1000000) {
			num = i + (i % 10) + ((i % 100 - i % 10) / 10) + ((i % 1000 - i % 100) / 100) + ((i % 10000 - i % 1000) / 1000) + ((i % 100000 - i % 10000) / 10000) + (i / 100000);
			if (num == n) {
				printf("%d", i);
				break;
			}
		}
	}
	if (i == 1000000) {
		printf("0");
	}

	return 0;
}