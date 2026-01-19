#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int num = 0;
	int cnt1 = 0;
	int cnt2 = 0;

	while (n > num) { // 최소 봉지수를 만드는 법은 크기 5의 봉지를 가장 많이 활용하는 방법이므로 5로 입력값의 크기를 짐작한다.
		num += 5;
		cnt1++;

		if (num == n) { // 만약 크기 5인 봉지에 모두 담긴다면 출력.
			printf("%d", cnt1);
			return 0;
		}
	}

	for (int i = 0; i < cnt1; i++) { // 입력값이 5로 나누어 떨어지지 않을 경우,
		cnt2 = 0;
		num = 5 * (cnt1 - i -1); // 5를 하나 빼고,
		while (n > num) { 
			num += 3; //  그 빈자리를 3으로 채워 모두 담기는지 확인한다.
			cnt2++;
			if (num == n) { // 만약 모두 담긴다면 봉지수 출력
				printf("%d", cnt2 + (cnt1 - i -1));
				return 0;
			}
		}
	}

	printf("-1"); // 만약 조건을 만족했다면 반복문 내에서 return 0;으로 인해 종료되었겠지만, 반복문을 탈출한 후에도 종료되지 않았다면 조건을 만족하지 못한 것이므로 -1을 출력한다.
	return 0;
}

