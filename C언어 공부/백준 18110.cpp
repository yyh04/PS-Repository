#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	vector<int> v;

	int n;
	cin >> n;

	if (n == 0) {

		cout << 0;
		return 0;

	}

	int num;

	for (int i = 0; i < n; i++) {

		cin >> num;
		v.push_back(num);

	}

	sort(v.begin(), v.end());

	int sum = 0;
	int k = round(n * 0.15);

	for (int i = k; i < n - k; i++) {

		sum += v[i];

	}

	cout << round((float)sum / (n - 2 * k));

	return 0;

}