#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long num;
	scanf("%d", &num);

	long long top = 1;
	long long bottom = num;
	long long hight = num*2;
	long long middle = num - 1;

	printf("%lld", top + bottom + hight + middle);
	return 0;
}