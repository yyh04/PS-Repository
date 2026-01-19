#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 10001
#include <stdio.h>
#include <string.h>

int queue[MAX_SIZE] = { 0, };
int queueSize = 0;

void push(int);
int pop();
int size();
int empty();
int front();
int back();

int main(void) {

	int N;
	int num;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {

		char function[6] = { 0, };

		scanf("%s", function);
		getchar();

		if (strcmp(function, "push") == 0) {

			scanf("%d", &num);
			getchar();
			push(num);

		}

		else if (strcmp(function, "pop") == 0) {

			printf("%d\n", pop());

		}

		else if (strcmp(function, "size") == 0) {

			printf("%d\n", size());

		}

		else if (strcmp(function, "empty") == 0) {

			printf("%d\n", empty());

		}

		else if (strcmp(function, "front") == 0) {

			printf("%d\n", front());

		}

		else if (strcmp(function, "back") == 0) {

			printf("%d\n", back());

		}

	}

	return 0;

}

void push(int num) {

	queue[queueSize] = num;
	queueSize++;

}

int pop() {

	if (queueSize == 0) {

		return -1;

	}

	else {

		int frontValue = queue[0];

		for (int i = 0; i < queueSize - 1; i++) {

			queue[i] = queue[i + 1];

		}

		queue[queueSize - 1] = 0;

		queueSize--;

		return frontValue;

	}

}

int size() {

	return queueSize;

}

int empty() {

	return (queueSize == 0) ? 1 : 0;

}

int front() {

	return (queueSize == 0) ? -1 : queue[0];

}

int back() {

	return (queueSize == 0) ? -1 : queue[queueSize-1];

}