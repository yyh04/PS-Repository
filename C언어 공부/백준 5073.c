#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	while (1) {
		int cnt = 0;
		int temp = 0;
		int tri[3] = { 0, };

		for (int i = 0; i < 3; i++) {
			scanf("%d", &tri[i]);
		}
		if (tri[0] > tri[1]) { // 버블 정렬 알고리즘 풀어씀
			temp = tri[0];
			tri[0] = tri[1];
			tri[1] = temp;
		}
		if (tri[1] > tri[2]) {
			temp = tri[1];
			tri[1] = tri[2];
			tri[2] = temp;
		}
		if (tri[0] > tri[1]) {
			temp = tri[0];
			tri[0] = tri[1];
			tri[1] = temp;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++) {
				if (tri[i] == tri[j]) {
					cnt++;
				}
			}
		}

		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0) {
			break;
		}
		else if (tri[2] >= tri[0] + tri[1]) {
			printf("Invalid\n");
		}
		else if (cnt == 6) {
			printf("Equilateral\n");
		}
		else if (cnt == 4) {
			printf("Isosceles\n");
		}
		else if (cnt == 3) {
			printf("Scalene\n");
		}
	}
	return 0;
}