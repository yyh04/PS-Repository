#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int waitingLine[1001] = { 0, };
int side[1001] = { 0, };
int sideHigh = -1;

int main(void) {

	int willBeTake = 1;
	int num = 0;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		scanf("%d", &waitingLine[i]);

	}

	while (willBeTake < N) {

		if (willBeTake != waitingLine[num] && num < N + 1) {

			side[++sideHigh] = waitingLine[num];
			waitingLine[num] = 0;
			num++;

		}

		else if (willBeTake == waitingLine[num]) {

			waitingLine[num] = 0;
			willBeTake++;
			num++;

		}

		while (willBeTake == side[sideHigh]) {

			willBeTake++;

			side[sideHigh] = 0;
			sideHigh--;

			if (waitingLine[num - 1] != 0) {

				num++;

			}

		}

		for (int i = 0; i < sideHigh; i++) {

			if (willBeTake == side[i]) {

				printf("Sad");

				return 0;

			}

		}


	}

	printf("Nice");

	return 0;

}