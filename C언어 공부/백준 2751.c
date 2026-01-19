#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

short int sorted[1000000] = { 0, };

void merge(short int a[], short int start, short int mid, short int end) {
	short int i = start;
	short int j = mid + 1;
	short int idx = start;

	while (i <= mid && j <= end) {
		if (a[i] >= a[j]) {
			sorted[idx] = a[j];
			j++;
		}

		else {
			sorted[idx] = a[i];
			i++;
		}
		idx++;
	}

	if (i > mid) {
		for (short int k = j; k <= end; k++) {
			sorted[idx] = a[k];
			idx++;
		}
	}
	else {
		for (short int k = i; k <= mid; k++) {
			sorted[idx] = a[k];
			idx++;
		}
	}

	for (shortint t = start; t <= end; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	int* arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0, n - 1);


	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}