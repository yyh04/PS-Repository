#include <iostream>
#include <string>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int a, b, c;
	string num;

	cin >> a >> b >> c;

	a *= b;
	a *= c;

	num = to_string(a);

	int arr[10] = { 0, };

	for (int i = 0; i < num.size(); i++) {

		arr[num[i] - '0']++;

	}

	for (int i = 0; i < 10; i++) {

		cout << arr[i] << '\n';

	}

	return 0;

}