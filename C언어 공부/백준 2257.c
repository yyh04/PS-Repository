#define _CRT_SECURE_NO_WARNINGS
#define H 1
#define C 12
#define O 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

	char key;

	struct Node* next;
	struct Node* previous;

}Node;

Node* head;
Node* tail;
Node* cursor;
Node* cursorOpen;
Node* cursorClose;

void Initialization();
int Find(int);
int Computing();
void Push(char);
void Delete(int);
int isEmpty();
void FreeAll();

int cnt = 0; // 노드의 개수


int main(void) {

	Initialization();

	int mass = 0;
	char ch = 1;

	while (1) {

		ch = getchar();

		if (ch == 10) {

			break;

		}

		Push(ch);

		cnt++;

	}

	while (isEmpty() == 0) {

		int length = Find(cnt);

		mass += Computing();

		Delete(length);

		cnt -= length;
		
	}

	printf("%d", mass);

	FreeAll();

	return 0;

}

void Initialization() {

	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));


	head->key = NULL;
	head->previous = NULL;
	head->next = tail;

	tail->key = NULL;
	tail->previous = head;
	tail->next = NULL;

}

int Find(int length) {

	int backword = 0;
	int frontword = 0;

	cursorOpen = tail;

	while (cursorOpen->key != '(' && cursorOpen != head->next) {

		cursorOpen = cursorOpen->previous;
		backword++;

	}

	cursorClose = cursorOpen;

	while (cursorOpen->key != ')' && cursorClose != tail->previous) {

		cursorClose = cursorClose->next;
		frontword++;

	}

	cursor = cursorOpen;

	if (cursorClose->next->key < 58 && 47 < cursorClose->next->key) {

		return (length == backword) ? length + 1 : frontword;

	}

	else {

		return (length == backword) ? length : frontword - 1;

	}

}

int Computing() {

	int mass = 0;

	if (cursor->key < 64) {
		
		cursor = cursor->next;

		Computing();

	}

	else if (cursor->key == ')') {

		return (cursor->next->key < 64) ? mass * (cursor->next->key) : mass;

	}

	else if (cursor->key == 'H') {

		if (cursor->next->key > 64 || cursor->next->key == 0) { // 알파벳 뒤에 또 알파벳이 온다면

			cursor = cursor->next;

			mass += H;

			Computing();

		}

		else {
			
			mass += H * (cursor->next->key - 48);

			cursor = cursor->next;

			Computing();

		}

	}

	else if (cursor->key == 'C') {

		if (cursor->next->key > 64 || cursor->next->key == 0) { // 알파벳 뒤에 또 알파벳이 온다면

			cursor = cursor->next;

			mass += C;

			Computing();

		}

		else {

			mass += C * (cursor->next->key - 48);

			cursor = cursor->next;

			Computing();

		}

	}

	else if (cursor->key == 'O') {

		if (cursor->next->key > 64 || cursor->next->key == 0) { // 알파벳 뒤에 또 알파벳이 온다면

			cursor = cursor->next;

			mass += O;

			Computing();

		}

		else {

			mass += O * (cursor->next->key - 48);

			cursor = cursor->next;

			Computing();

		}

	}

}

void Push(char data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = data;
	newNode->previous = tail->previous;
	newNode->next = tail;

	newNode->previous->next = newNode;
	tail->previous = newNode;

}

void Delete(int length) {

	Node* willBeDeletedNode1 = cursorOpen->next;

	cursorOpen->previous->next = cursorClose->next;
	cursorClose->next->previous = cursorOpen->previous;

	for (int i = 0; i < length - 1; i++) {

		Node* willBeDeletedNode2 = willBeDeletedNode1->previous;

		willBeDeletedNode1 = willBeDeletedNode1->next;

		if (willBeDeletedNode1 == tail) {

			free(willBeDeletedNode2->next);

		}

		free(willBeDeletedNode2);

	}

}

int isEmpty() {

	if (head->next == tail) {

		return 1;

	}

	else {

		return 0;

	}

}

void FreeAll() {

	Node* willBeDeletedNode1 = head->next;

	while (willBeDeletedNode1 != tail) {

		Node* willBeDeletedNode2 = willBeDeletedNode1->previous;

		free(willBeDeletedNode2);

		willBeDeletedNode1 = willBeDeletedNode1->next;
	}

	free(tail->previous);
	free(tail);

}