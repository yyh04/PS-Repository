#include <iostream>

using namespace std;

int dp[101] = { 0, };

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	for (int i = 1; i < 101; i++) {

		int cnt = 0;
		int num = i * 5;

		while (num % 5 == 0) {

			num /= 5;
			cnt++;

		}

		dp[i] = dp[i - 1] + cnt;

	}

	int n;
	cin >> n;

	cout << dp[n / 5] << '\n';

	return 0;

}