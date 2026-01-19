#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char string[101] = { 0, };

	scanf("%s", string);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (string[10 * i + j] != 0) {
				printf("%c", string[10 * i + j]);
			}
		}
		printf("\n");
	}

	return 0;
}