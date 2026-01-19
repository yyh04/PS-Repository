#include <iostream>

using namespace std;

int main(void) {
	int n = 1, m = 1;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		else if (n > m) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}