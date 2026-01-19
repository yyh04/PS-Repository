#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	int num;

	for (int i = 0; i < n; i++) {

		cin >> num;
		v.push_back(num);

	}

	sort(v.begin(), v.end());

	int small_sum = 0;
	int big_sum = 0;

	for (int i = 0; i < n; i++) {

		small_sum = 0;

		for (int j = 0; j <= i; j++) {

			small_sum += v[j];

		}

		big_sum += small_sum;

	}

	cout << big_sum;

	return 0;

}