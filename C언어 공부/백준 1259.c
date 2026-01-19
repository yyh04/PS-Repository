#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {

	int num;
	int digit;
	int digitCount;
	int isPalindrome = 1;
	int number[5] = { 0, };
	int rnumber[5] = { 0, };

	while (1) {

		scanf("%d", &num);

		if (num == 0) {

			return 0;

		}

		digit = floor(log10(num) + 1);
		digitCount = digit;

		for (int i = 0; i < digit; i++) {

			number[i] = (num % (int)pow(10, digitCount) / pow(10, digitCount - 1));
			digitCount--;

		}

		for (int i = 0; i < digit; i++) {

			rnumber[i] = number[digit - 1 - i];

			if (rnumber[i] != number[i]) {

				isPalindrome = 0;

			}

		}

		if (isPalindrome == 1) {

			printf("yes\n");

		}

		else if (isPalindrome == 0) {

			printf("no\n");

		}

		isPalindrome = 1;

	}

	return 0;

}