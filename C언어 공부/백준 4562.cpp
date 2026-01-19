#include <iostream>

using namespace std;

int main(void) {
	int n;
	int x, y;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		if (x < y) {
			cout << "NO BRAINS\n";
		}
		else {
			cout << "MMM BRAINS\n";
		}
	}

	return 0;
}