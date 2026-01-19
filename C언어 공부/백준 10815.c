#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(void const* first, void const* second) {
	int* fst = (int*)first;
	int* snd = (int*)second;

	return *(fst)-*(snd);
}

int binarySearch(int* arrn, int start, int end, int num) {
	int mid = (start + end) / 2;
	if (*(arrn + mid) == num || *(arrn + mid + 1) == num) {
		return 1;
	}
	else if (mid == start || mid == end) {
		return 0;
	}
	else if(*(arrn + mid) > num) {
		binarySearch(arrn, start, mid, num);
	}
	else if (*(arrn + mid) < num) {
		binarySearch(arrn, mid, end, num);
	}
}

int main(void) {
	int n, m;
	scanf("%d", &n);

	int* arrn = (int*)calloc(n, sizeof(int));


	for (int i = 0; i < n; i++) {
		scanf("%d", (arrn + i));
	}

	scanf("%d", &m);

	int* arrm = (int*)calloc(m, sizeof(int));
	int* result = (int*)calloc(m, sizeof(int));

	for (int i = 0; i < m; i++) {
		scanf("%d", (arrm + i));
	}

	qsort(arrn, n, sizeof(int), compare);

	for (int i = 0; i < m; i++) {
		printf("%d ", binarySearch(arrn, 0, n - 1, *(arrm + i)));
	}

	return 0;
}