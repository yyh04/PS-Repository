#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {

	int num[3] = { 0, };
	int result = 1;
	int numberOfDigit = 0;
	
	for (int i = 0; i < 3; i++) {

		scanf("%d", &num[i]);

		result *= num[i];

	}

	numberOfDigit = floor(log(result) + 1);

	for (int i = 0; i < numberOfDigit; i++) {



	}

	return 0;

}