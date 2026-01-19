#include <iostream>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c) {

		cout << -1 << '\n';

	}

	else {

		cout << a / (c - b) + 1 << '\n';

	}

	return 0;

}