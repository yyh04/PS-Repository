#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int key;

	struct Node* next;
	struct Node* previous;

}Node;

Node* head;
Node* tail;
Node* cursor;

void Initialization();
void MoveCursor(int);
void InsertNode(int);
void print();
void DeleteNode();

int main(void) {

	int n, k;
	scanf("%d %d", &n, &k);

	Initialization();

	for (int i = 0; i < n; i++) {

		InsertNode(i + 1);

	}

	printf("<");

	for (int i = 0; i < n; i++) {

		MoveCursor(k);
		print();
		DeleteNode();

		if (i != n - 1) {

			printf(", ");

		}

	}

	printf(">");

	return 0;

}

void Initialization() {

	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	cursor = head;

	head->key = NULL;
	head->previous = tail;
	head->next = tail;

	tail->key = NULL;
	tail->previous = head;
	tail->next = head;

}

void MoveCursor(int time) {

	for (int i = 0; i < time - 1; i++) {

		cursor = cursor->next;

	}

}

void InsertNode(int data) {

	if (head->key == NULL) {

		head->key = data;

	}

	else if (tail->key == NULL) {

		tail->key = data;

	}

	else {

		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->key = tail->key;
		newNode->previous = tail->previous;
		newNode->next = tail;

		tail->key = data;
		tail->previous->next = newNode;
		tail->previous = newNode;

	}

}

void print() {

	printf("%d", cursor->key);

}

void DeleteNode() {
	
	Node* willBeDeletedNode;

	if (cursor == head) {

		willBeDeletedNode = cursor->next;

		head->key = head->next->key;
		head->next->next->previous = head;
		head->next = head->next->next;

	}

	else if (cursor == tail) {

		cursor = cursor->next;
		willBeDeletedNode = cursor->previous->previous;

		tail->key = tail->previous->key;
		tail->previous->previous->next = tail;
		tail->previous = tail->previous->previous;

	}

	else {

		cursor = cursor->next;
		willBeDeletedNode = cursor->previous;

		cursor->previous->previous->next = cursor;
		cursor->previous = cursor->previous->previous;

	}

	free(willBeDeletedNode);

}