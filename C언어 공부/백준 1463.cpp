#include <iostream>
#include <vector>

using namespace std;

int arr[1000000] = { 0, };

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i <= n; i++) {

		arr[i] = arr[i - 1] + 1;

		if (!(i % 3)) {

			arr[i] = min(arr[i], arr[i / 3] + 1);

		}

		if (!(i % 2)) {

			arr[i] = min(arr[i], arr[i / 2] + 1);

		}

	}

	cout << arr[n] << '\n';

	return 0;

}