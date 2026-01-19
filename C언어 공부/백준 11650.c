#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}Point;

int compare(const void* first, const void* second) {
	Point* p1 = (Point*)first;
	Point* p2 = (Point*)second;

	if (p1->x > p2->x) {
		return 1;
	}
	else if (p1->x < p2->x) {
		return -1;
	}
	else {
		if (p1->y > p2->y) {
			return 1;
		}
		else if (p1->y < p2->y) {
			return -1;
		}
	}
	return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);

	Point* arr = (Point*)calloc(n, sizeof(Point));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	qsort(arr, n, sizeof(Point), compare);
	

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	free(arr);
	return 0;
}