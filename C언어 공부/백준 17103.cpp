	#include <iostream>

	using namespace std;

	int arr[1000001] = { 0, };

	int main(void) {

		for (int i = 2; i <= 1000000; i++) {

			arr[i] = i;

		}

		for (int i = 2; i * i <= 1000000; i++) {

			for (int j = i * i; j <= 1000000; j += i) {

				arr[j] = 0;

			}

		}

		int t;
		cin >> t;

		for (int i = 0; i < t; i++) {

			int cnt = 0;
			int num;
			cin >> num;

			for (int j = 0; j <= num / 2; j++) {

				if (arr[j] != 0 && arr[num - j] != 0) {

					cnt++;

				}

			}

			cout << cnt << '\n';

		}

		return 0;

	}