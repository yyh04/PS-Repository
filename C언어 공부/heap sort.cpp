#include <stdio.h>

int main(void) {

	int number = 9;
	int heap[9] = { 3, 2, 4, 1, 5, 9, 6, 7, 8 };
	int root, c;

	for (int i = 1; i < number; i++) { // ÃÖ´ë Èü ±¸¼º

		c = i;

		do {

			root = (c - 1) / 2;

			if (heap[root] < heap[c]) {

				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;

			}

			c = root;

		} while (c != 0);

	}

	for (int i = number - 1; i >= 0; i--) {

		root = 0;

		int temp = heap[root];
		heap[root] = heap[i];
		heap[i] = temp;

		do {

			c = root * 2 + 1;

			if (c < i - 1 && heap[c] < heap[c + 1]) {

				c++;

			}

			if (c < i && heap[c] > heap[root]) {

				temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;

			}

			root = c;

		} while (c < i);

	}

	for (int i = 0; i < number; i++) {

		printf("%d ", heap[i]);

	}

	return 0;

}