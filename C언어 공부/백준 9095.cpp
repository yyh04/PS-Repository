#include <iostream>
#include <vector>

using namespace std;

int arr[12] = { 0, };

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int t;
	cin >> t;

	int num;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++) {

		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

	}

	for (int i = 0; i < t; i++) {

		cin >> num;

		cout << arr[num] << '\n';

	}

	return 0;

}