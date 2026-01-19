#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
	int same = 0;

	scanf("%d %d %d %d %d %d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);

	if (p1x == p2x) { // xÁÂÇ¥ Ã£±â
		p4x = p3x;
	}
	else if (p2x == p3x) {
		p4x = p1x;
	}
	else {
		p4x = p2x;
	}

	if (p1y == p2y) { // yÁÂÇ¥ Ã£±â
		p4y = p3y;
	}
	else if (p2y == p3y) {
		p4y = p1y;
	}
	else {
		p4y = p2y;
	}

	printf("%d %d", p4x, p4y);

	return 0;
}