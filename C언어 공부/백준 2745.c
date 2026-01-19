#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	int B;
	int len = 0;
	long long dec = 0;
	char* N = (char*)malloc(sizeof(char) * 32);

	scanf("%s %d", N, &B);

	len = strlen(N);

	for (int i = 0; i < len; i++) {
		if (47 < N[i] && N[i] < 58) {
			dec += (N[i] - 48) * pow(B, len - i - 1);
		}
		else if (64 < N[i] && N[i] < 91) {
			dec += (N[i] - 55) * pow(B, len - i - 1);
		}
	}

	printf("%lld", dec);
	free(N);
	return 0;
}