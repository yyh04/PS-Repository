#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k, cnt = 0;

	scanf("%d %d", &n, &k);

	int* arr = (int*)calloc(n, sizeof(int));

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[cnt] = i;
			cnt++;
		}
	}

	if (arr[0] == 0 || arr[k-1] == 0) {
		printf("0");
	}
	else {
		printf("%d", arr[k - 1]);
	}

	free(arr);
	return 0;
}