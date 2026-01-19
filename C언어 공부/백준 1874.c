#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100000] = { 0, };
int high = -1;

void push(int);
void pop();

int main(void) {

	char plusMinus[200000];
	int cntPlusMinus = 0;
	int impossible = 0;
	int cnt = 0;
	int num[100000] = { 0, };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &num[i]);

	}

	for (int i = 0; i < n; i++) {

		if (num[cnt] != stack[high]) {

			push(i + 1);
			plusMinus[cntPlusMinus] = '+';
			cntPlusMinus++;

		}


		while (num[cnt] == stack[high]) {

			pop();
			plusMinus[cntPlusMinus] = '-';
			cntPlusMinus++;
			cnt++;

			for (int j = 0; j < high; j++) {
				
				if (cnt[num] == stack[j]) {
					impossible = 1;
				}

			}

			if (cnt == n) {

				break;

			}

		}

	}

	if (impossible == 1) {

		printf("NO");
	}

	else {

		for (int i = 0; i < cntPlusMinus; i++) {

			printf("%c\n", plusMinus[i]);

		}

	}

	return 0;

}

void push(int pushNum) {

	high++;
	stack[high] = pushNum;

}

void pop() {

	stack[high] = 0;
	high--;

}