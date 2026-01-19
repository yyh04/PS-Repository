#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	int value;
	struct node* next;
};

struct bucket {
	int cnt;
	struct node* head;
};

struct bucket* hashTable = NULL;
int SIZE = 10;

int hashFunction(int key) {
	return key % SIZE;
}

struct node* createNode(int key, int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void insert(int key, int value) {
	int hashIndex = hashFunction(key);
	struct node* node = createNode(key, value);

	if (hashTable[hashIndex].cnt == 0) {
		hashTable[hashIndex].head = node;
		hashTable[hashIndex].cnt = 1;
	}
	else {
		node->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = node;
		hashTable[hashIndex].cnt++;
	}

	return;
}

void remov(int key) {
	int hashIndex = hashFunction(key);
	struct node* node = hashTable[hashIndex].head;
	struct node* trace = node;
	
	if (hashTable[hashIndex].cnt == 0) {
		printf("\nno node found");
		return;
	}

	while (node != NULL) {
		if (node->key == key) {
			if (node = hashTable[hashIndex].head) {
				hashTable[hashIndex].head = node->next;
			}
			else {
				trace->next = node->next;
			}
			
			hashTable[hashIndex].cnt--;
			free(node);
			return;
		}

		trace = node;
		node = node->next;
	}

	printf("\nno key found");
	return;
}

void search(int key) {
	int hashIndex = hashFunction(key);
	struct node* node = hashTable[hashIndex].head;

	if (hashTable[hashIndex].cnt == 0) {
		printf("\nno node found");
		return;
	}
	while (node != NULL) {
		if (node->key == key) {
			printf("\nBucket[%d]: key = %d, value = %d", hashIndex, node->key, node->value);
			return;
		}
		node = node->next;
	}
	printf("\nno key found");
	return;
}

void display() {
	struct node* node;

	for (int i = 0; i < SIZE; i++) {
		node = hashTable[i].head;
		while (node != NULL) {
			printf("\nBucket[%d]: key = %d, value = %d", i, node->key, node->value);
			node = node->next;
		}
	}

	printf("\n----------end of display----------\n");
	return;
}

int main(void) {
	hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket));

	for (int i = 0; i < SIZE; i++) {
		hashTable[i].head = NULL;
		hashTable[i].cnt = 0;
	}

	insert(0, 1);
	insert(1, 10);
	insert(11, 90);
	insert(21, 64);
	insert(31, 23);
	insert(6, 25);
	insert(97, 4);

	search(97);
	search(3);

	display();

	return 0;
}