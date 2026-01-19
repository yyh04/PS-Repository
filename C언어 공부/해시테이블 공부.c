#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node { // key값과 value값을 포함하는 노드 구조체
	int key;
	int value;
	struct node* next; // 충돌을 해결하기 위해 chaining을 사용할 것이므로 각 노드가 다음 노드를 포인팅 하고 있어야 함
};

struct bucket { // 해시테이블의 인덱스 역할. 하나의 버켓에 여러 노드가 들어있을 수 있음 (충돌을 피하기 위해 chaining 사용)
	struct node* head; // 헤드 노드
	int cnt; // 버켓에 들어있는 노드의 개수를 카운트
};

struct bucket* hashTable = NULL; // 해시테이블
int SIZE = 10; // 헤시테이블의 크기를 10으로 지정

struct node* createNode(int key, int value) { // 사용자가 입력한 key값과 value값으로 노드를 생성하는 함수
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode; // 생성된 노드 반환
}

int hashFunction(int key) { // 해시함수, 다른 함수를 사용하여도 됨
	return key % SIZE;
}

void insert(int key, int value) { // 새로운 노드를 삽입하는 함수, 새로 들어오는 노드를 해당 버켓의 헤드 노드로 지정
	int hashIndex = hashFunction(key); // 다루어야할 인덱스를 선언
	struct node* newNode = createNode(key, value); // createNode함수를 통해 새로 생성된 노드 불러오기

	if (hashTable[hashIndex].cnt == 0) { // 해당 버켓에 아무런 노드가 없는 경우
		hashTable[hashIndex].head = newNode; // 아무런 노드가 없으므로 첫 노드가 헤드가 됨
		hashTable[hashIndex].cnt = 1; // 첫 노드를 삽입했으므로 cnt를 1로 설정
	}
	else { // 해당 버켓에 노드가 있을 경우
		newNode->next = hashTable[hashIndex].head; // 충돌을 피하기 위해 chaining을 사용하므로 새로 들어올 노드가 원래 헤드 노드를 포인팅하도록 함
		hashTable[hashIndex].head = newNode; // 새로 들어오는 노드를 헤드 노드로 지정
		hashTable[hashIndex].cnt++; // 해당 버켓의 노드 수가 하나 늘어났으므로 증가 연산자 사용
	}

	return; // 함수 탈출
}

void rmov(int key) { // 버켓에 있는 노드를 제거하는 함수
	int hashIndex = hashFunction(key); // 다루어야할 인덱스를 선언
	struct node* node; // 노드를 사용하기 위한 선언
	struct node* trace = hashTable[hashIndex].head; // 노드를 제거할 때, 제거 당하는 노드가 포인팅 하고 있는 노드를, 제거 당하는 노드를 포인팅 하고 있는 노드가 포인팅 할 수 있도록 하는 포인터 선언
	node = hashTable[hashIndex].head; // 가장 마지막에 들어온 노드가 헤드 노드이므로 노드를 헤드 해당 버켓의 헤드 노드로 초기화
	trace = node; // trace는 node와 같은 노드를 지칭함

	if (node == NULL) { // 버켓에 노드가 없는 경우
		printf("\nno node found\n");

		return;
	}
	while (node != NULL) { // 포인팅하는 노드가 없을 때까지 반복 = 마지막 노드까지 반복
		if (key == node->key) { // 동일한 key값을 가지는 노드를 찾은 경우
			if (node == hashTable[hashIndex].head) { // 그 노드가 해드노드라면
				hashTable[hashIndex].head = node->next; // 헤드노드가 포인팅 하고 있던 노드를 헤드노드로 전환 (헤드노드가 삭제되면 새로운 헤드노드가 있어야 하기 때문)
			}
			else { // 그 노드가 헤드노드가 아니라면
				trace->next = node->next; // 삭제 당할 노드가 포인팅 하고 있는 노드를 삭제 당하는 노드를 포인팅하고 있는 노드가 포인팅할 수 있도록 함
			}

			hashTable[hashIndex].cnt--; // 버켓에서 노드를 삭제하므로 cnt값 감소
			free(node); // 메모리를 해제하여 해시테이블에서 삭제

			return; // 함수 종료
		}
		trace = node; // trace는 node와 같은 노드를 가리킴
		node = node->next; // 노드를 포인팅하고 있는 노드로 전환하여 다시 탐색
	}
	printf("\nno key found\n"); // 버켓에 동일한 key값을 가지는 노드를 찾지 못했을 경우 출력
	return; // 함수 종료
}

void search(int key) { // 해시테이블에 해당 노드가 존재하는지 판단하는 함수
	int hashIndex = hashFunction(key); // 다루어야할 인덱스를 선언
	struct node* node = hashTable[hashIndex].head; // 기본 노드를 해당 버켓의 헤드노드로 선언

	if (node == NULL) { // 버켓에 노드가 존재하지 않는 경우
		printf("\nno node found\n"); // 출력

		return; // 함수 종료
	}
	while (node != NULL) { // 버켓의 마지막 노드까지 반복
		if (node->key == key) { // 버켓에서 해당 key값을 가진 노드를 찾았다면
			printf("노드가 존재합니다.\nkey: %d & value: %d\n", node->key, node->value); // 출력

			return; // 함수 종료
		}
		node = node->next; // 노드의 key값이 찾고자 하는 key값이 아닐 경우 포인팅하고 있는 노드로 node를 변경 후 반복
	}

	printf("\nno key found\n"); // 버켓에 있는 모드 노드에 찾고자 하는 key값을 가진 노드가 없을 경우 출력

	return; // 함수 종료
}

void display() { // 해시테이블을 출력하는 함수
	struct node* node; // 노드 구조체를 포인팅하는 node 선언

	for (int i = 0; i < SIZE; i++) { // 해시테이블 크기만큼 반복
		node = hashTable[i].head; // 해당 버켓의 헤드노드로 초기화
		while (node != NULL) { // 버켓의 마지막 노드까지 반복
			printf("Bucket[%d] : key = %d : value = %d\n", i + 1, node->key, node->value); // 노드 출력

			node = node->next; // 다음 노드로 변경
		}

		printf("\n");
	}

	printf("\n---------end of display---------\n"); // display함수가 끝났음을 알림

	return; // 모두 출력하면 함수 종료
}

int main(void) {

	hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket)); // 해시테이블 초기화

	for (int i = 0; i < SIZE; i++) {
		hashTable[i].head = NULL; // 노드를 NULL로 초기화
		hashTable[i].cnt == 0; //  버켓의 노드 개수 0으로 초기화
	}

	insert(0, 1);
	insert(1, 10);
	insert(11, 90);
	insert(21, 64);
	insert(31, 23);
	insert(6, 25);
	insert(97, 4);

	display();

	rmov(31);
	rmov(11);

	display();

	return 0;
}