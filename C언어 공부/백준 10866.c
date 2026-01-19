#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

	int key;

	struct Node* next;
	struct Node* previous;

}Node;

Node* head;
Node* tail;

void Initialization();
void push_front(int data);
void push_back(int data);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();
void FreeAll();


int main(void) {

	Initialization();

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		char order[11] = { 0, };
		scanf("%s", order);

		if (strcmp(order, "push_front") == 0) {

			int data = 0;
			scanf("%d", &data);

			push_front(data);

		}

		else if (strcmp(order, "push_back") == 0) {

			int data = 0;
			scanf("%d", &data);

			push_back(data);

		}

		else if (strcmp(order, "pop_front") == 0) {

			printf("%d\n", pop_front());

		}

		else if (strcmp(order, "pop_back") == 0) {

			printf("%d\n", pop_back());

		}

		else if (strcmp(order, "size") == 0) {

			printf("%d\n", size());

		}

		else if (strcmp(order, "empty") == 0) {

			printf("%d\n", empty());

		}

		else if (strcmp(order, "front") == 0) {

			printf("%d\n", front());

		}

		else if (strcmp(order, "back") == 0) {

			printf("%d\n", back());

		}

	}

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

void push_front(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = data;
	newNode->previous = head;
	newNode->next = head->next;

	head->next->previous = newNode;
	head->next = newNode;

}

void push_back(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = data;
	newNode->previous = tail->previous;
	newNode->next = tail;

	tail->previous->next = newNode;
	tail->previous = newNode;

}

int pop_front() {

	if (empty() == 1) {

		return -1;

	}

	else {

		Node* willBeDeletedNode = head->next;
		int wilBePrintedKey = willBeDeletedNode->key;

		willBeDeletedNode->next->previous = head;
		head->next = willBeDeletedNode->next;

		free(willBeDeletedNode);

		return wilBePrintedKey;

	}

}

int pop_back() {

	if (empty() == 1) {

		return -1;

	}

	else {

		Node* willBeDeletedNode = tail->previous;
		int wilBePrintedKey = willBeDeletedNode->key;

		willBeDeletedNode->previous->next = tail;
		tail->previous = willBeDeletedNode->previous;

		free(willBeDeletedNode);

		return wilBePrintedKey;

	}

}

int size() {

	Node* cursor = head;
	int count = 0;

	while (cursor->next != tail) {

		cursor = cursor->next;
		count++;

	}

	return count;

}

int empty() {

	return (size() == 0) ? 1 : 0;

}

int front() {

	if (empty() == 1) {

		return -1;

	}

	else {

		return head->next->key;

	}

}

int back() {

	if (empty() == 1) {

		return -1;

	}

	else {

		return tail->previous->key;

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