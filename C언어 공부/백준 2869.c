#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long wood, morning, night, day;
	scanf("%d %d %d", &morning, &night, &wood);

	if ((wood - morning) % (morning - night) == 0) {
		day = (wood - morning) / (morning - night) + 1;
	}
	else {
		day = (wood - morning) / (morning - night) + 2;
	}

	printf("%lld", day);
	return 0;
}

/*
int main(void) {
	int wood = 0; // 나무 높이
	int height = 0; // 현재 높이
	int morning = 0; // 아침에 올라가는 거리
	int night = 0; // 밤에 내려가는 거리
	int day = 1; // 일수

	scanf("%d %d %d", &morning, &night, &wood);

	while (height < wood) {
		height += morning;
		if (height >= wood) { // 아침에 도착했을 경우
			break;
		}
		height -= night;
		day++;
	}

	printf("%d", day);
	return 0;
}
*/