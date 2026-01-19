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

void Initialization();
void InsertNode(int data);
void DeleteLastNode();
void FreeAll();


int main(void) {



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

void InsertNode(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = data;
	newNode->previous = tail->previous;
	newNode->next = tail;

	newNode->previous->next = newNode;
	tail->previous = newNode;

}

void DeleteLastNode() {

	Node* willBeDeletedNode = tail->previous;

	tail->previous->previous->next = tail;
	tail->previous = tail->previous->previous;

	free(willBeDeletedNode);

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