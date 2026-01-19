#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int len;
	char str[50];
}String;

int compare(const void* first, const void* second) {
	String* fst = (String*)first;
	String* snd = (String*)second;

	if ((fst->len) > (snd->len)) {
		return 1;
	}
	else if ((fst->len) < (snd->len)) {
		return -1;
	}
	else {
		if (strcmp(fst->str, snd->str) > 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);

	String* string = (String*)calloc(n, sizeof(String));

	for (int i = 0; i < n; i++) {
		scanf("%s", (string + i)->str);
		(string + i)->len = strlen((string + i)->str);
	}

	qsort(string, n, sizeof(String), compare);

	puts(string->str);

	for (int i = 1; i < n; i++) {
		if (strcmp((string + i - 1)->str, (string + i)->str)) {
			puts((string + i)->str);
		}
	}

	return 0;
}