#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age; // 나이
	int idx; // 등록순
	char name[101]; // 이름
}Member;

int compare(const void* first, const void* second){
	Member* fst = (Member*)first;
	Member* snd = (Member*)second;

	if (fst->age > snd->age) { // 나이 먼저 비교
		return 1;
	}
	else if (fst->age < snd->age) {
		return -1;
	}
	else { // 나이가 같을 경우
		if (fst->idx > snd->idx) { // 등록순 비교
			return 1;
		}
		else if (fst->idx < snd->idx) {
			return -1;
		}
	}

	return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);

	Member* member = (Member*)calloc(n, sizeof(Member));

	for (int i = 0; i < n; i++) {
		scanf("%d%*c%s", &((member + i)->age), (member+i)->name); // %*c -> 공백 무시
		((member+i)->idx) = i;
	}

	qsort(member, n, sizeof(Member), compare);


	for (int i = 0; i < n; i++) {
		printf("%d %s\n", (member + i)->age, (member + i)->name);
	}


	free(member);
	return 0;
}