#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char arr[5][15] = { 0, };
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr[i]); // 문자열은 문자 배열 한 칸이 여러 개 모인 것이므로 이렇게 만들어도 무방함.
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (arr[i][j] == NULL) { // 빈칸일 경우 무시함.
				continue;
			}
			printf("%c", arr[i][j]);
		}
	}

	return 0;
}