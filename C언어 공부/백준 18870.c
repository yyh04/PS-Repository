#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int idx;
	int num;
}Point;



int compare(const void* first, const void* second) {
	Point* fst = (Point*)first;
	Point* snd = (Point*)second;

	return (fst->num) - (snd->num);
}

int main(void) {
	int min = INT_MIN;
	int cnt = -1;
	int n;
	scanf("%d", &n);
	Point* pnt = (Point*)calloc(n, sizeof(Point));

	int* result = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &(pnt + i)->num);
		(pnt + i)->idx = i;
	}

	qsort(pnt, n, sizeof(Point), compare);

	for (int i = 0; i < n; i++) {
		if (min != (pnt + i)->num) {
			min = (pnt + i)->num;
			cnt++;
		}
		*(result + (pnt + i)->idx) = cnt;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", *(result + i));
	}

	free(pnt);
	return 0;
}

/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int press;
	int num;
}Point1;

typedef struct {
	int press;
	int num;
}Point2;

int compare(const void* first, const void* second) {
	Point1* fst = (Point1*)first;
	Point1* snd = (Point1*)second;

	return (fst->num) - (snd->num);
}

int main(void) {
	int n;
	scanf("%d", &n);
	Point1* pnt1 = (Point1*)calloc(n, sizeof(Point1));
	Point2* pnt2 = (Point2*)calloc(n, sizeof(Point2));

	for (int i = 0; i < n; i++) {
		scanf("%d", &(pnt1 + i)->num);
		(pnt2 + i)->num = (pnt1 + i)->num ;
	}

	qsort(pnt2, n, sizeof(Point1), compare);

	pnt2->press = 0;

	for (int i = 1; i < n; i++) {
		if ((pnt2 + i)->num == (pnt2 + i - 1)->num) {
			(pnt2 + i)->press = (pnt2 + i - 1)->press;
		}
		else {
			(pnt2 + i)->press = ((pnt2 + i - 1)->press) + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((pnt1 + i)->num == (pnt2 + j)->num) {
				(pnt1 + i)->press = (pnt2 + j)->press;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", (pnt1 + i)->press);
	}

	free(pnt1);
	free(pnt2);
	return 0;
}*/