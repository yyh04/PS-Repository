#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int*, int, int, int);
int compare(const void*, const void*);

int main(void) {

    int n, m;

    scanf("%d", &n);

    int* arrn = calloc(n, sizeof(int));

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

        printf("%d\n", BinarySearch(arrn, arrm[i], 0, n));

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

int BinarySearch(int* arrn, int target, int start, int end) {

    int mid = (start + end) / 2;

    if (arrn[mid] == target) {

        return 1;

    }

    else if (mid == start) {

        return 0;

    }

    else if (arrn[mid] < target) {

        BinarySearch(arrn, target, mid, end);

    }

    else if (arrn[mid] > target) {

        BinarySearch(arrn, target, start, mid);

    }

}