#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int n, cnt = 0;
	int num = 665;

	scanf("%d", &n);

	while (1) {
		if (cnt == n) {
			break;
		}
		num++;

		for (int i = 0; i < 10; i++) {
			if (num / (int)pow(10, i) % 1000 == 666) {
				cnt++;
				break;
			}
		}
	}
	printf("%d\n", num);
	return 0;
}