#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int l;
	cin >> l;

	string str;
	cin >> str;

	long long num = 0;
	long long r = 1;

	for (int i = 0; i < l; i++) {

		num = (num + (str[i] - 96) * r) % 1234567891;
		r = (r * 31) % 1234567891;

	}

	cout << num;

	return 0;

}