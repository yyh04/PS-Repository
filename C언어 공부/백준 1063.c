#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int king[2] = { 0, };
int stone[2] = { 0, };

int main(void) {

	int attemp = 0;
	char order[3] = { 0, };

	for (int i = 0; i < 2; i++) {

		char ch = getchar();

		king[i] = ch;

	}

	getchar();

	for (int i = 0; i < 2; i++) {

		char ch = getchar();

		stone[i] = ch;

	}

	getchar();
	scanf("%d", &attemp);

	for (int i = 0; i < attemp; i++) {

		scanf("%s", order);

		switch (order[0]) {

		case 'T':

			if (king[1] - 48 == 8 || (king[0] == stone[0] && king[1] + 1 == stone[1] && stone[1] - 48 == 8)) {

				break;

			}

			else if (king[0] == stone[0] && king[1] + 1 == stone[1] && stone[1] - 48 != 8) {

				king[1]++;
				stone[1]++;

			}

			else {

				king[1]++;

			}

			break;

		case 'B':

			if (king[1] - 48 == 1 || (king[0] == stone[0] && king[1] - 1 == stone[1] && stone[1] - 48 == 1)) {

				break;

			}

			else if (king[0] == stone[0] && king[1] - 1 == stone[1] && stone[1] - 48 != 1) {

				king[1]--;
				stone[1]--;

			}

			else {

				king[1]--;

			}

			break;

		case 'R':

			switch (order[1]) {

			case'T':

				if (king[0] == 'H' || king[1] - 48 == 8 || (king[0] + 1 == stone[0] && king[1] + 1 == stone[1] && (stone[0] == 'H' || stone[1] - 48 == 8))) {

					break;

				}

				else if (king[0] + 1 == stone[0] && king[1] + 1 == stone[1] && stone[0] != 'H' && stone[1] - 48 != 8) {

					king[0]++;
					king[1]++;
					stone[0]++;
					stone[1]++;

				}

				else {

					king[0]++;
					king[1]++;

				}

				break;

			case 'B':

				if (king[0] == 'H' || king[1] - 48 == 1 || (king[0] + 1 == stone[0] && king[1] - 1 == stone[1] && (stone[0] == 'H' || stone[1] - 48 == 1))) {

					break;

				}

				else if (king[0] + 1 == stone[0] && king[1] - 1 == stone[1] && stone[0] != 'H' && stone[1] - 48 != 1) {

					king[0]++;
					king[1]--;
					stone[0]++;
					stone[1]--;

				}

				else {

					king[0]++;
					king[1]--;

				}

				break;

			case '\0':

				if (king[0] == 'H' || (king[0] + 1 == stone[0] && king[1] == stone[1] && stone[0] == 'H')) {

					break;

				}

				else if (king[0] + 1 == stone[0] && king[1] == stone[1] && stone[0] != 'H') {

					king[0]++;
					stone[0]++;

				}

				else {

					king[0]++;

				}

				break;

			}

			break;

		case 'L':

			switch (order[1]) {

			case 'T':

				if (king[0] == 'A' || king[1] - 48 == 8 || (king[0] - 1 == stone[0] && king[1] + 1 == stone[1] && (stone[0] == 'A' || stone[1] - 48 == 8))) {

					break;

				}

				else if (king[0] - 1 == stone[0] && king[1] + 1 == stone[1] && stone[0] != 'A' && stone[1] - 48 != 8) {

					king[0]--;
					king[1]++;
					stone[0]--;
					stone[1]++;

				}

				else {

					king[0]--;
					king[1]++;

				}

				break;

			case 'B':

				if (king[0] == 'A' || king[1] - 48 == 1 || (king[0] - 1 == stone[0] && king[1] - 1 == stone[1] && (stone[0] == 'A' || stone[1] - 48 == 1))) {

					break;

				}

				else if (king[0] - 1 == stone[0] && king[1] - 1 == stone[1] && stone[0] != 'A' && stone[1] - 48 != 1) {

					king[0]--;
					king[1]--;
					stone[0]--;
					stone[1]--;

				}

				else {

					king[0]--;
					king[1]--;

				}

				break;

			case '\0':

				if (king[0] == 'A' || (king[0] - 1 == stone[0] && king[1] == stone[1] && stone[0] == 'A')) {

					break;

				}

				else if (king[0] - 1 == stone[0] && king[1] == stone[1] && stone[0] != 'A') {

					king[0]--;
					stone[0]--;

				}

				else {

					king[0]--;

				}

				break;

			}

			break;

		}

	}

	printf("%c%d\n", king[0], king[1] - 48);
	printf("%c%d", stone[0], stone[1] - 48);

	return 0;

}