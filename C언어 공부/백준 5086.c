#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int fst = 0, snd = 0;

	while (1) {
		scanf("%d %d", &fst, &snd);

		if (fst == 0 && snd == 0) {
			break;
		}

		if (snd % fst == 0) {
			printf("factor\n");
		}

		else if (fst % snd == 0) {
			printf("multiple\n");
		}

		else {
			printf("neither\n");
		}
	}

	return 0;
}