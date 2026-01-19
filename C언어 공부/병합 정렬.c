#include <stdio.h>

int sorted[8];
int num = 8;

void merge(int a[], int str, int mid, int end) {
	int fst1 = str;
	int fst2 = mid + 1;
	int std = str;

	while (fst1 <= mid && fst2 <= end) {
		if (a[fst1] <= a[fst2]) {
			sorted[std] = a[fst1];
			fst1++;
		}
		else {
			sorted[std] = a[fst2];
			fst2++;
		}
		std++;
	}

	if (fst1 > mid) {
		for (int i = fst2; i <= end; i++) {
			sorted[std] = a[i];
			std++;
		}
	}
	else {
		for (int i = fst1; i <= mid; i++) {
			sorted[std] = a[i];
			std++;
		}
	}

	for (int i = str; i <= end; i++) {
		a[i] = sorted[i];
	}
}

void mergeSort(int a[], int str, int end) {
	if (str < end) {
		int mid = (str + end) / 2;
		mergeSort(a, str, mid);
		mergeSort(a, mid + 1, end);
		merge(a, str, mid, end);
	}
}

int main(void) {
	int arr[8] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(arr, 0, num - 1); // end값 -1 신경쓰기

	for (int i = 0; i < num; i++) {
		printf("%d", sorted[i]);
	}

	return 0;
}