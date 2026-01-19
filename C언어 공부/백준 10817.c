#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second) {
	int* fst = (int*)first;
	int* snd = (int*)second;
	return *fst - *snd;
}

int main(void) {
	int arr[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, 3, sizeof(int), compare);

	printf("%d", arr[1]);

	return 0;
}