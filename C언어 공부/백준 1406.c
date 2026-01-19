#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	char key;
	struct Node* next;
	struct Node* previous;

}Node;

Node* head;
Node* tail;
Node* cursor;


void initialization();
void left();
void right();
void insertNode(char);
void deleteNode();
void deleteAll();
void print();

int main(void) {

	int integer;
	char character;

	initialization();

	while ((character = getchar()) != '\n') {

		insertNode(character);

	}

	scanf("%d", &integer);
	getchar();

	for (int i = 0; i < integer; i++) {

		scanf("%c", &character);
		getchar();

		switch (character) {
			
		case 'L':

			left();

			break;
			
		case 'D':

			right();

			break;

		case 'B':

			deleteNode();

			break;

		case 'P':

			scanf("%c", &character);
			getchar();

			insertNode(character);

			break;

		}

	}


	print();
	deleteAll();

	return 0;

}

void initialization() {

	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	head->previous = NULL;
	head->next = tail;
	tail->previous = head;
	tail->next = NULL;
	cursor = head;

}

void left() {

	if (cursor != head) {

		cursor = cursor->previous;

	}

}

void right() {

	if (cursor != tail -> previous) {

		cursor = cursor->next;

	}

}

void insertNode(char alpabet) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = alpabet;
	newNode->previous = cursor;
	newNode->next = cursor->next;
	cursor->next->previous = newNode;
	cursor->next = newNode;
	cursor = newNode;

}

void deleteNode() {

	if (cursor != head) {

		Node* willBeFreedNode = cursor;

		cursor = cursor->previous;
		cursor->next = willBeFreedNode->next;
		willBeFreedNode->next->previous = cursor;

		free(willBeFreedNode);

	}

}

void deleteAll() {

	Node* murder1 = head;

	while (murder1 != tail) {

		Node* murder2 = murder1;

		murder1 = murder1->next;

		free(murder2);

	}

	free(tail);

}

void print() {

	Node* reader = head->next;

	while (reader != tail) {

		printf("%c", reader->key);

		reader = reader->next;

	}

}