#include <iostream>

using namespace std;

int arr[300001] = { 0, };

int main(void) {

	for (int i = 2; i <= 300000; i++) {

		arr[i] = i;

	}

	for (int i = 2; i * i <= 300000; i++) {

		if (arr[i] == 0) {

			continue;

		}

		for (int j = i * i; j <= 300000; j += i) {

			arr[j] = 0;

		}

	}

	while (1) {

		int cnt = 0;
		int num;
		cin >> num;

		if (num == 0) {

			return 0;

		}

		for (int i = num + 1; i <= 2 * num; i++) {

			if (arr[i] != 0) {

				cnt++;

			}

		}

		cout << cnt << '\n';

	}

	return 0;

}