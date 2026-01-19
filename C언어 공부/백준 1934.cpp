#include <iostream>

using namespace std;

int main(void) {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int a, b;
		cin >> a >> b;

		int num;
		int max;

		if (a >= b) {

			num = a;

			while (num != 0) {

				if (a % num == 0 && b % num == 0) {

					max = num;
					break;

				}

				num--;

			}

		}

		else {

			num = b;

			while (num != 0) {

				if (a % num == 0 && b % num == 0) {

					max = num;
					break;

				}

				num--;

			}

		}

		cout << max * (a / max) * (b / max) << '\n';

	}

}