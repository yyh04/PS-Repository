#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) { // 한 대각선(좌하향)에서 좌하향으로 갈 수록 분모는 1씩 감소하고 분자는 1씩 증가한다는 규칙이 있음
	int arith = 2; // 계차수열
	int num = 1;
	int cnt = 1;
	int x = 0;

	scanf("%d", &x);

	while (num < x) { //x가 몇 번째 대각선(=cnt)에 있는지 파악
		cnt++;
		num += arith;
		arith += 1;a
	}

	int pos = x - (num - arith + 1); // 대각선 중에서 몇 번째 칸인지
	int numerator = 0;
	int dominator = 0;

	if ((cnt % 2) == 0) { // 지그재그로 수 세는 것 고려
		numerator = pos; // 분자
		dominator = cnt - pos + 1; // 분모
		printf("%d/%d", numerator, dominator);
	}

	else {
		numerator = cnt - pos + 1;
		dominator = pos;
		printf("%d/%d", numerator, dominator);
	}

	return 0;
}