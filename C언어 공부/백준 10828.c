#define _CRT_SECURE_NO_WARNINGS
#define stackSize 10001
#include <stdio.h>
#include <string.h>

int empty(); // 빈 스택인지 확인 참이면 1, 거짓이면 0
void push(int); // 매개변수 스택 맨 위에 쌓기
void pop(); // 빈 스택이면 -1, 아니면 맨 위 스택 출력 후 삭제
void size(); // 스택 크기 출력
void top(); // 빈 스택이면 -1, 아니면 맨 위 스택값 출력

int high = -1;
int stack[stackSize] = { 0, };

int main(void) {
	int n;
	int num;
	char str[6] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%s", str);
		if (str != 0) {
		}

		if (!strcmp(str, "push")) {
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(str, "pop")) {
			pop();
		}
		else if (!strcmp(str, "size")) {
			size();
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(str, "top")) {
			top();
		}
	}

	
	return 0;
}

void push(int num) {
	high++;
	stack[high] = num;
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