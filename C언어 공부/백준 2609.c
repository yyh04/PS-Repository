#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int A, B;
	scanf("%d %d", &A, &B);
	int a = A, b = B;

	if (A >= B) {

		while (1) { 

			if ((A % b == 0) && (B % b == 0)) {

				printf("%d\n", b);

				break;

			}

			b--;

		}

		a = b * (A / b) * (B / b);

		printf("%d\n", a);

	}

	else if (A < B) {

		while (1) { 

			if ((A % a == 0) && (B % a == 0)) {

				printf("%d\n", a);

				break;

			}

			a--;

		}

		b = a * (A / a) * (B / a);

		printf("%d\n", b);

	}


	return 0;

}