#define _CRT_SECURE_NO_WARNINGS
#define stackSize 1000001
#include <stdio.h>

int stack[stackSize] = { 0, };
int high = -1;

void push(int);
void delete();

int main(void) {
	int k;
	int fncNum;
	long long sum = 0;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {

		scanf("%d", &fncNum);

		if (fncNum == 0) {
			delete();
		}
		else {
			push(fncNum);
		}
	}

	for (int i = 0; i < high + 1; i++) {
		sum += stack[i];
	}

	printf("%lld", sum);

	return 0;
}

void push(int fncNum) {
	high++;
	stack[high] = fncNum;
}

void delete() {
	stack[high] = 0;
	high--;
}