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
	void DeleteTopNode();
	void MoveToBottom();
	void FreeAll();


	int main(void) {

		Initialization();

		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {

			InsertNode(i + 1);

		}

		while (head->next->next != tail) {

			DeleteTopNode();

			if (head->next->next != tail) {

				MoveToBottom();

			}

		}

		printf("%d", head->next->key);

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

	void InsertNode(int data) {

		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->key = data;
		newNode->previous = tail->previous;
		newNode->next = tail;

		newNode->previous->next = newNode;
		tail->previous = newNode;

	}

	void DeleteTopNode() {

		Node* willBeDeletedNode = head->next;

		head->next->next->previous = head;
		head->next = head->next->next;

		free(willBeDeletedNode);

	}

	void MoveToBottom() {

		InsertNode(head->next->key);
		DeleteTopNode();

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