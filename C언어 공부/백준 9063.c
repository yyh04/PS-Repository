#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int max_x = -10000;
	int max_y = -10000;
	int min_x = 10000;
	int min_y = 10000;
	
	scanf("%d", &n);

	int* x = (int*)calloc(n, sizeof(int));
	int* y = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (max_x <= x[i]) { // 가장 오른쪽 점
			max_x = x[i];
		}
		if (max_y <= y[i]) { // 가장 위쪽 점
			max_y = y[i];
		}
		if (min_x >= x[i]) { // 가장 왼쪽 점
			min_x = x[i];
		}
		if (min_y >= y[i]) { // 가장 아래쪽 점
			min_y = y[i];
		}
	}

	printf("%d", (max_x - min_x) * (max_y - min_y));
	return 0;
}