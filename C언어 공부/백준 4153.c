#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const int* first, const int* second) {

	return (*first) - (*second);

}

int main(void) {

	int length[3] = { 1, 1, 1 };

	while (1) {

		for (int i = 0; i < 3; i++) {

			scanf("%d", &length[i]);

		}

		qsort(length, 3, sizeof(int), compare);

		if (length[0] == 0 && length[1] == 0 && length[2] == 0) {

			break;

		}

		if (length[0] * length[0] + length[1] * length[1] == length[2] * length[2]) {
			
			printf("right\n");

		}

		else {

			printf("wrong\n");

		}

	}

	return 0;

}