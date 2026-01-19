//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int smallHigh = -1;
//int bigHigh = -1;
//
//typedef struct smallNode {
//
//	char key;
//
//	struct smallNode* next;
//	struct smallNode* previous;
//
//}smallNode;
//
//typedef struct bigNode {
//
//	char key;
//
//	struct smallNode* next;
//	struct smallNode* previous;
//
//}bigNode;
//
//smallNode* smallHead;
//smallNode* smallTail;
//
//bigNode* bigHead;
//bigNode* bigTail;
//
//void Initialization();
//void InsertSmallNode(char);
//void InsertBigNode(char);
//void DeleteSmallNode();
//void DeleteBigNode();
//void AllFree();
//
//int main(void) {
//	char string[101] = { 0, };
//	
//	while (1) {
//
//		scanf("%[^\n]s", string);
//		getchar();
//
//		if (string[0] == '.') {
//
//			break;
//
//		}
//
//		Initialization();
//
//		for (int i = 0; i < strlen(string); i++) {
//
//			if (string[i] == '(') {
//
//				InsertSmallNode('(');
//
//			}
//
//			else if (string[i] == ')') {
//
//				InsertSmallNode(')');
//
//				if (smallTail->previous->previous->key == '(' && smallTail->previous->key == ')') {
//
//					DeleteSmallNode();
//
//				}
//
//			}
//
//			if (string[i] == '[') {
//
//				InsertBigNode('[');
//
//			}
//
//			else if (string[i] == ']') {
//
//				InsertBigNode(']');
//
//				if (bigTail->previous->previous->key == '[' && bigTail->previous->key == ']') {
//
//					DeleteBigNode();
//
//				}
//
//			}
//
//		}
//
//		if (smallHead->next == smallTail && bigHead->next == bigTail) {
//
//			printf("yes\n");
//
//		}
//
//		else {
//
//			printf("no\n");
//
//		}
//
//		AllFree();
//
//	}
//
//	return 0;
//
//}
//
//void Initialization() {
//
//	smallHead = (smallNode*)malloc(sizeof(smallNode));
//	smallTail = (smallNode*)malloc(sizeof(smallNode));
//
//	bigHead = (bigNode*)malloc(sizeof(bigNode));
//	bigTail = (bigNode*)malloc(sizeof(bigNode));
//
//	smallHead->previous = NULL;
//	smallHead->next = smallTail;
//	smallTail->previous = smallHead;
//	smallTail->next = NULL;
//
//	bigHead->previous = NULL;
//	bigHead->next = bigTail;
//	bigTail->previous = bigHead;
//	bigTail->next = NULL;
//
//}
//
//void InsertSmallNode(char parenthesis) {
//
//	smallHigh++;
//
//	smallNode* newSmallNode = (smallNode*)malloc(sizeof(smallNode));
//
//	newSmallNode->key = parenthesis;
//	
//	newSmallNode->next = smallTail;
//	newSmallNode->previous = smallTail->previous;
//	smallTail->previous->next = newSmallNode;
//	smallTail->previous = newSmallNode;
//
//
//}
//
//void InsertBigNode(char bracket) {
//
//	bigHigh++;
//
//	bigNode* newBigNode = (bigNode*)malloc(sizeof(bigNode));
//
//	newBigNode->key = bracket;
//
//	newBigNode->next = bigTail;
//	newBigNode->previous = bigTail->previous;
//	bigTail->previous->next = newBigNode;
//	bigTail->previous = newBigNode;
//
//}
//
//void DeleteSmallNode() {
//
//	smallHigh -= 2;
//
//	smallNode* willBeDeletedSmallNode = (smallNode*)malloc(sizeof(smallNode));
//	willBeDeletedSmallNode = smallTail->previous->previous;
//
//	smallTail->previous->previous->previous->next = smallTail;
//	smallTail->previous = smallTail->previous->previous->previous;
//
//	free(willBeDeletedSmallNode->next);
//	free(willBeDeletedSmallNode);
//
//}
//
//void DeleteBigNode() {
//
//	bigHigh -= 2;
//
//	bigNode* willBeDeletedBigNode = (bigNode*)malloc(sizeof(bigNode));
//	willBeDeletedBigNode = bigTail->previous->previous;
//
//	bigTail->previous->previous->previous->next = bigTail;
//	bigTail->previous = bigTail->previous->previous->previous;
//
//	free(willBeDeletedBigNode->next);
//	free(willBeDeletedBigNode);
//
//}
//
//void AllFree() {
//
//	smallNode* willBeAllDeletedSmallNode1 = (smallNode*)malloc(sizeof(smallNode));
//	bigNode* willBeAllDeletedBigNode1 = (bigNode*)malloc(sizeof(bigNode));
//
//	willBeAllDeletedSmallNode1 = smallHead->next;
//	willBeAllDeletedBigNode1 = bigHead->next;
//
//	for (int j = 0; j < smallHigh + 1; j++) {
//
//		smallNode* willBeAllDeletedSmallNode2 = (smallNode*)malloc(sizeof(smallNode));
//
//		willBeAllDeletedSmallNode2 = willBeAllDeletedSmallNode1->previous;
//		willBeAllDeletedSmallNode1 = willBeAllDeletedSmallNode1->next;
//
//		free(willBeAllDeletedSmallNode2);
//		//smallTail free ¾È µÊ
//	}
//
//	for (int j = 0; j < bigHigh + 1; j++) {
//
//		bigNode* willBeAllDeletedBigNode2 = (bigNode*)malloc(sizeof(bigNode));
//
//		willBeAllDeletedBigNode2 = willBeAllDeletedBigNode1->previous;
//		willBeAllDeletedBigNode1 = willBeAllDeletedBigNode1->next;
//
//		free(willBeAllDeletedBigNode2);
//		//bigTail free ¾È µÊ
//	}
//
//	free(smallTail);
//	free(bigTail);
//
//}

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
	char string[101] = { 0, };

	while (1) {

		scanf("%[^\n]s", string);
		getchar();

		if (string[0] == '.') {

			break;

		}

		Initialization();

		for (int i = 0; i < strlen(string); i++) {

			if (string[i] == '(') {

				InsertNode('(');

			}

			else if (string[i] == ')') {

				InsertNode(')');

				if (tailNode->previous->previous->key == '(' && tailNode->previous->key == ')') {

					DeleteNode();

				}

			}

			if (string[i] == '[') {

				InsertNode('[');

			}

			else if (string[i] == ']') {

				InsertNode(']');

				if (tailNode->previous->previous->key == '[' && tailNode->previous->key == ']') {

					DeleteNode();

				}

			}

		}

		if (headNode->next == tailNode) {

			printf("yes\n");

		}

		else {

			printf("no\n");

		}

		AllFree();
		high = -1;

	}

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