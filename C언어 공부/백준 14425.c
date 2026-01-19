#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char stringA[501];
}A;

typedef struct {
	char stringB[501];
}B;

int compare(const void* first, const void* second) {
	A* fst = (A*)first;
	A* snd = (A*)second;

	return (strcmp(fst->stringA, snd->stringA));
}

int binarySearch(A* a, int start, int end, char* string) {
	A* list = (A*)a;
	int mid = (start + end) / 2;

	if (strcmp((list + mid)->stringA, string) == 0 || strcmp((list + mid + 1)->stringA, string) == 0) {
		return 1;
	}
	else if (mid == start || mid == end) {
		return 0;
	}
	else if (strcmp((list + mid)->stringA, string) > 0) {
		binarySearch(a, start, mid, string);
	}
	else if (strcmp((list + mid)->stringA, string) < 0) {
		binarySearch(a, mid, end, string);
	}
}

int main(void) {
	int cnt = 0;
	int n, m;
	scanf("%d %d", &n, &m);

	A* a = (A*)calloc(n, sizeof(A));
	B* b = (B*)calloc(m, sizeof(B));

	for (int i = 0; i < n; i++) {
		scanf("%s", &((a + i)->stringA));
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", &((b + i)->stringB));
	}
	
	qsort(a, n, sizeof(A), compare);

	for (int i = 0; i < m; i++) {
		if (binarySearch(a, 0, n - 1, (b + i)->stringB) == 1) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}