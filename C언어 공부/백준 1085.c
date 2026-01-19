#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) { // 조건식 연산자 사용해보기
	int x, y, w, h;
	int lenW, lenH;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (w - x > x) {
		lenW = x;
	}
	else {
		lenW = w - x;
	}

	if (h - y > y) {
		lenH = y;
	}
	else {
		lenH = h - y;
	}

	if (lenW > lenH) {
		printf("%d", lenH);
	}
	else {
		printf("%d", lenW);
	}
	return 0;
}