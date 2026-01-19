#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char stack[1001][21] = { 0, };
int high[1001];

int main(void) {

	int T;

	scanf("%d", &T);
	getchar();

	for (int x = 0; x < T; x++) {

		int howManyStacks = 1;
		int howManyAlpabets = 0;
		char string[1001];

		scanf("%[^\n]s", string);
		getchar();


		for (int i = 0; i < 1001; i++) {

			high[i] = -1;

		}

		for (int i = 0; i < 1001; i++) {

			if (string[i] == ' ') {

				high[howManyStacks - 1] = howManyAlpabets - 1;
				howManyStacks++;
				howManyAlpabets = 0;

			}

			else if (string[i] == '\0') {

				high[howManyStacks - 1] = howManyAlpabets - 1;
				howManyAlpabets = 0;

				break;

			}

			else {

				stack[howManyStacks - 1][howManyAlpabets] = string[i];
				howManyAlpabets++;

			}
		}

		for (int i = 0; i < howManyStacks; i++) {

			for (int j = high[i]; j > -1; j--) {

				printf("%c", stack[i][j]);

			}

			if (i != howManyStacks - 1) {

				printf(" ");

			}

		}

		printf("\n");

	}

	return 0;
}