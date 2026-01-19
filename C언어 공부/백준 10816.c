#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int LowerBoundBinarySearch(int*, int, int, int);
int UpperBoundBinarySearch(int*, int, int, int);
int compare(const void*, const void*);

int main(void) {

	int n, m;

	scanf("%d", &n);

	int* arrn = calloc(n + 1, sizeof(int));

	for (int i = 0; i < n; i++) {

		scanf("%d", &arrn[i]);

	}

	qsort(arrn, n, sizeof(int), compare);

	scanf("%d", &m);

	int* arrm = calloc(m, sizeof(int));

	for (int i = 0; i < m; i++) {

		scanf("%d", &arrm[i]);

	}

	for (int i = 0; i < m; i++) {

		int UpperBound = UpperBoundBinarySearch(arrn, arrm[i], 0, n);
		int LowerBound = LowerBoundBinarySearch(arrn, arrm[i], 0, n);

		printf("%d ", UpperBound - LowerBound);

	}

	return 0;

}

int compare(const void* first, const void* second) {

	if (*(int*)first >= *(int*)second) {

		return 1;

	}

	else {

		return -1;

	}

}

int LowerBoundBinarySearch(int* arrn, int target, int start, int end) {

	int lowerBound = -1;
	int mid = (start + end) / 2;

	if (start >= end) {

		return start;

	}

	else if (target <= arrn[mid]) {

		end = mid;

		LowerBoundBinarySearch(arrn, target, start, end);

	}

	else if (arrn[mid] < target) {

		start = mid + 1;

		LowerBoundBinarySearch(arrn, target, start, end);

	}


}

int UpperBoundBinarySearch(int* arrn, int target, int start, int end) {

	int mid = (start + end) / 2;

	if (start >= end) {

		return start;

	}

	else if (target < arrn[mid]) {

		end = mid;

		UpperBoundBinarySearch(arrn, target, start, end);

	}

	else if (arrn[mid] <= target) {

		start = mid + 1;

		UpperBoundBinarySearch(arrn, target, start, end);

	}


}