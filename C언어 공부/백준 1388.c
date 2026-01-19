#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void horizon(char**, int, int, int);
void vertical(char**, int, int, int);

int main(void) {

	int x, y;
	int result = 0;

	scanf("%d %d", &y, &x);

	char** map = (char**)malloc(sizeof(char*) * (y + 1));

	for (int i = 0; i < y; i++) {

		map[i] = (char*)malloc(sizeof(char) * (x + 1));

	}

	for (int i = 0; i < y; i++) {

		scanf("%s", map[i]);

	}

	for (int i = 0; i < y; i++) {

		for (int j = 0; j < x; j++) {

			if (map[i][j] == '-') {

				horizon(map, j, i, x);
				result++;

			}

			else if (map[i][j] == '|') {

				vertical(map, j, i, y);
				result++;

			}

		}

	}

	printf("%d", result);

	return 0;

}

void horizon(char** map, int x, int y, int lastX) {

	for (int a = x + 1; a < lastX; a++) {

		if (map[y][a] == '|' || map[y][a] == '.') {

			break;

		}

		else if (map[y][a] == '-') {

			map[y][a] = '.';

		}

	}

}

void vertical(char** map, int x, int y, int lastY) {

	for (int b = y + 1; b < lastY; b++) {

		if (map[b][x] == '-' || map[b][x] == '.') {

			break;

		}

		else if (map[b][x] == '|') {

			map[b][x] = '.';

		}

	}

}