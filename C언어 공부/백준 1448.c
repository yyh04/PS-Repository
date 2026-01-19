//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//int compare(const int*, const int*);
//
//int main(void) {
//
//	int max = 0;
//	int N;
//
//	scanf("%d", &N);
//
//	int* arr = calloc(N, sizeof(int));
//
//	for (int i = 0; i < N; i++) {
//
//		scanf("%d", &arr[i]);
//
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			for (int k = j + 1; k < N; k++) {
//
//				int sum = 0;
//				int triangle[3] = { arr[i], arr[j], arr[k] };
//
//				qsort(triangle, 3, sizeof(int), compare);
//
//				if (triangle[2] < triangle[0] + triangle[1]) {
//
//					sum = triangle[0] + triangle[1] + triangle[2];
//
//				}
//
//				if (max < sum) {
//					max = sum;
//				}
//
//				sum = 0;
//
//			}
//		}
//	}
//
//	if (max == 0) {
//
//		printf("-1");
//
//	}
//	else {
//
//		printf("%d", max);
//
//	}
//
//	return 0;
//
//}
//
//int compare(const int* first, const int* second) {
//
//	return *first - *second;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const int*, const int*);

int main(void) {

	int isTriangle = 0;
	int max = 0;
	int N;

	scanf("%d", &N);

	int* arr = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {

		scanf("%d", &arr[i]);

	}

	qsort(arr, N, sizeof(int), compare);


	for (int i = N - 1; i > 1; i--) {

		if (arr[i] < arr[i - 2] + arr[i - 1]) {

			isTriangle = 1;
			int sum = arr[i - 2] + arr[i - 1] + arr[i];

			if (max < sum) {
				max = sum;
			}

		}

	}

	if (isTriangle == 0) {

		printf("-1");

	}
	else {

		printf("%d", max);

	}

	return 0;

}

int compare(const int* first, const int* second) {

	return *first - *second;

}
