#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count[10001] = { 0, };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int m;
		cin >> m;

		count[m]++;

	}

	for (int i = 1; i < 10001; i++) {

		if (count[i] == 0) {

			continue;

		}

		for (int j = 0; j < count[i]; j++) {

			cout << i << '\n';

		}

	}


	return 0;

}