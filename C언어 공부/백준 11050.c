#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Factorial(int);

int main(void) {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", Factorial(a) / (Factorial(b) * Factorial(a - b)));

	return 0;

 }

int Factorial(int num) {

	int returnValue  = 1;

	for (int i = 0; i < num; i++) {

		returnValue *= num - i;

	}

	return returnValue;

}