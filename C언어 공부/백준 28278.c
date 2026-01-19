#define _CRT_SECURE_NO_WARNINGS
#define stackSize 1000001
#include <stdio.h>

int empty();
void push(int);
void pop();
void size();
void top();

int high = -1;
int stack[stackSize] = { 0, };

int main(void) {
	int N;
	int X;
	int fncNum;

	scanf("%d", &N);
	if (N != 0) {
	}

	for (int i = 0; i < N; i++) {

		scanf("%d", &fncNum);

		if (fncNum == 1) {
			scanf("%d", &X);
			push(X);
		}
		else if (fncNum == 2) {
			pop();
		}
		else if (fncNum == 3) {
			size();
		}
		else if (fncNum == 4) {
			printf("%d\n", empty());
		}
		else if (fncNum == 5) {
			top();
		}
	}

	return 0;
}

void push(int X) {
	high++;
	stack[high] = X;
}

void pop() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[high]);
		stack[high] = 0;
		high--;
	}
}

void size() {
	printf("%d\n", high + 1);
}

int empty() {
	if (high == -1) {
		return 1;
	}
	else
		return 0;
}

void top() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[high]);
	}
}