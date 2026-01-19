#include <iostream>

using namespace std;

int main(void) {

	long long a, b;
	cin >> a >> b;

	long long num;
	long long max;

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