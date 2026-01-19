#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char num[10] = { 0, };
	int temp;

	scanf("%s", num);
	int len = strlen(num);

	for (int i = 0; i < 9; i++) { // 버블 정렬
		for (int j = 0; j < 9 - i; j++) {
			if (num[j] < num[j + 1]) {
				temp = num[j + 1];
				num[j + 1] = num[j];
				num[j] = temp;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		printf("%c", num[i]);
	}

	return 0;
}