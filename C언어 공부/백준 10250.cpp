#include <iostream>

using namespace std;

int main(void) {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int h, w, n;
		cin >> h >> w >> n;

		if ((n / h) + 1 > 9) {

			cout << n % h << (n / h) + 1 << '\n';

		}

		else {

			cout << n % h << 0 << (n / h) + 1 << '\n';

		}

	}

	return 0;

}