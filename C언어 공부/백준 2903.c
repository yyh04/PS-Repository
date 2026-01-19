#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int time = 0;
	int pnt = 0;

	scanf("%d", &time);

	pnt = pow(pow(2, time) + 1, 2);
	printf("%d", pnt);

	return 0;
}