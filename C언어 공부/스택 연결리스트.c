#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int high = -1;

typedef struct Node {

	char key;

	struct Node* next;
	struct Node* previous;

}Node;

Node* headNode;
Node* tailNode;

void Initialization();
void InsertNode(char);
void DeleteNode();
void AllFree();

int main(void) {



	return 0;

}

void Initialization() {

	headNode = (Node*)malloc(sizeof(Node));
	tailNode = (Node*)malloc(sizeof(Node));

	headNode->previous = NULL;
	headNode->next = tailNode;
	tailNode->previous = headNode;
	tailNode->next = NULL;

}

void InsertNode(char character) {

	high++;

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->key = character;

	newNode->next = tailNode;
	newNode->previous = tailNode->previous;
	tailNode->previous->next = newNode;
	tailNode->previous = newNode;

}

void DeleteNode() {

	high -= 2;

	Node* willBeDeletedNode = (Node*)malloc(sizeof(Node));
	willBeDeletedNode = tailNode->previous->previous;

	tailNode->previous->previous->previous->next = tailNode;
	tailNode->previous = tailNode->previous->previous->previous;

	free(willBeDeletedNode->next);
	free(willBeDeletedNode);

}

void AllFree() {

	Node* willBeAllDeletedNode1 = (Node*)malloc(sizeof(Node));

	willBeAllDeletedNode1 = headNode->next;

	for (int j = 0; j < high + 2; j++) {

		Node* willBeAllDeletedNode2 = (Node*)malloc(sizeof(Node));

		willBeAllDeletedNode2 = willBeAllDeletedNode1->previous;
		willBeAllDeletedNode1 = willBeAllDeletedNode1->next;

		free(willBeAllDeletedNode2);
	}

	free(tailNode);

}