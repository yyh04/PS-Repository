#include <iostream>

using namespace std;

int dp[15][15] = { 0, };

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	for (int i = 0; i < 15; i++) {

		dp[i][1] = 1;
		dp[0][i] = i;

	}

	for (int i = 1; i < 15; i++) {

		for (int j = 2; j < 15; j++) {

			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

		}

	}

	int t;
	cin >> t;

	int n, k;

	for (int i = 0; i < t; i++) {

		cin >> k >> n;

		cout << dp[k][n] << '\n';

	}

	return 0;

}