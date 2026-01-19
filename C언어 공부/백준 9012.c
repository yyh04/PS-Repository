#define _CRT_SECURE_NO_WARNINGS
#define stackSize 51
#include <stdio.h>

char stack[stackSize];
int high = -1;

void push();
void pop();

int main(void) {
	int T;
	char bracketArr[stackSize];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", bracketArr);

		for (int j = 0; j < stackSize; j++) {
			if (high == -1 && bracketArr[j] == ')') {
				high = 100;
				break;
			}
			else if (bracketArr[j] == ')' && high > -1) {
				pop();
			}
			else if (bracketArr[j] == '(') {
				push();
			}
			else {
				break;
			}
		}

		if (high == -1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		high = -1;
	}

	return 0;
}

void push() {
	high++;
	stack[high] = '(';
}

void pop() {
	stack[high] = '\0';
	high--;
	
}