#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	int num;
	char title[100];
};

void showBook(struct Book*, int);

int main(void) {
	struct Book *b;
	b = (struct Book*)malloc(2 * sizeof(struct Book));

	if (b == NULL) {
		printf("동적 메모리 할당에 실패했습니다.");
		exit(1);
	}

	b->num = 1;
	strcpy(b->title, "C Programming\n");

	(b + 1)->num = 2;
	strcpy((b + 1)->title, "Data Structure");

	showBook(b, 2);

	free(b);
	return 0;
}

void showBook(struct Book* b, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d번 : %s", (b+i)->num, (b+i)->title);
	}
}