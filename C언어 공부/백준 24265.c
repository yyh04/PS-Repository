#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long n;
	scanf("%lld", &n);

	printf("%lld\n2", n * (n - 1) / 2);
	return 0;
}