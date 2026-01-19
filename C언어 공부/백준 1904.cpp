#include <iostream>

using namespace std;

int dp[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i - 2] + dp[i - 3]) % 15746;
	}

	cout << dp[n];
	return 0;
}