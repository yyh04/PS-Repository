#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* HowManyDifferent(int**, int**, int, int);
void Change(int**, int*);
int IsSame(int**, int**);

int main(void) {

	int count = 0;

	int arr1[50][50] = { 0, };
	int arr2[50][50] = { 0, };

	int row1 = 0, column1 = 0;
	int row2 = 0, column2 = 0;

	int rowSize, columnSize;

	scanf("%d %d", &columnSize, &rowSize);
	getchar();

	for (int i = 0; i < columnSize; i++) { // arr1 입력

		for (int j = 0; j < rowSize; j++) {

			char gc = getchar();
			arr1[i][j] = gc - '0';

		}

		getchar();

	}

	for (int i = 0; i < columnSize; i++) { // arr2 입력

		for (int j = 0; j < rowSize; j++) {

			char gc = getchar();
			arr2[i][j] = gc - '0';

		}

		getchar();

	}

	if (columnSize < 3 && rowSize < 3) { // 크기가 너무 작은 경우

		printf("-1");

		return 0;

	}

	while (!IsSame(arr1, arr2, rowSize, columnSize)) {

		Change(arr1, HowManyDifferent(arr1, arr2, rowSize, columnSize));
		count++;

	}

	printf("%d", count);

	return 0;

}

int* HowManyDifferent(int** arr1[][50], int** arr2[][50], int rowSize, int columnSize) {

	int maxValue = 0;
	static int willBeReturnedPoint[2] = { 0, };
	int cnt = 0;
	int howManyDifferent = 0;
	int maxPoint[2209][3] = {0,};

	for (int a = 0; a < columnSize - 2; a++) {

		for (int b = 0; b < rowSize - 2; b++) {

			for (int c = a; c < a + 2; c++) {

				for (int d = b; d < b + 2; d++) {

					if (arr1[c][d] == arr2[c][d]) {

						howManyDifferent++;

					}

				}

			}

			maxPoint[cnt][0] = howManyDifferent;
			maxPoint[cnt][1] = a; // 행
			maxPoint[cnt][2] = b; // 열

			cnt++;

		}

	}

	for (int i = 0; i < cnt; i++) {

		if (maxPoint[i][0] > maxValue) {

			maxValue = maxPoint[i][0];
			willBeReturnedPoint[0] = maxPoint[i][1]; // 행
			willBeReturnedPoint[1] = maxPoint[i][2]; // 열

		}

	}

	return willBeReturnedPoint;

}


void Change(int** arr1[][50], int* willBeReturnedPoint) {

	for (int i = willBeReturnedPoint[0]; i < willBeReturnedPoint[0] + 2; i++) {

		for (int j = willBeReturnedPoint[1]; j < willBeReturnedPoint[1] + 2; j++) {

			if (arr1[i][j] == 1) {

				arr1[i][j] == 0;

			}

			else if (arr1[i][j] == 0) {

				arr1[i][j] == 1;

			}

		}

	}

}

int IsSame(int** arr1[][50], int** arr2[][50], int rowSize, int columnSize) {

	int isSame = 1;

	for (int i = 0; i < columnSize; i++) {

		for (int j = 0; j < rowSize; j++) {

			if (arr1[i][j] != arr2[i][j]) {

				isSame = 0;

				return isSame;

			}

		}

	}

}