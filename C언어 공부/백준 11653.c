#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int div = 2;

	scanf("%d", &n);

	while (n != 1) {
		if (n % div == 0) {
			n /= div;
			printf("%d\n",div);	
		}
		else {
			div++;
		}
	}

	return 0;
}