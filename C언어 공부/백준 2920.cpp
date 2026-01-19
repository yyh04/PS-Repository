#include <iostream>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int arr[8] = { 0, };

	for (int i = 0; i < 8; i++) {

		cin >> arr[i];

	}

	if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5 && arr[5] == 6 && arr[6] == 7 && arr[7] == 8) {

		cout << "ascending" << '\n';

	}

	else if (arr[0] == 8 && arr[1] == 7 && arr[2] == 6 && arr[3] == 5 && arr[4] == 4 && arr[5] == 3 && arr[6] == 2 && arr[7] == 1) {

		cout << "descending" << '\n';

	}

	else {

		cout << "mixed" << '\n';

	}

	return 0;

}