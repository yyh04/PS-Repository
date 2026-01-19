#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int testCase = 0;
	int change = 0; // ¼¾Æ®
	int quarter = 0, dime = 0, nickel = 0, penny = 0; // 25, 10, 5, 1

	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		scanf("%d", &change);

		quarter = change / 25;
		change %= 25;
		dime = change / 10;
		change %= 10;
		nickel = change / 5;
		change %= 5;
		penny = change / 1;
		change %= 1;
		
		printf("%d %d %d %d\n", quarter, dime, nickel, penny);
	}
	return 0;
}