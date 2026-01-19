#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500][500] = { 0, };
int dp[500][500] = { 0, };

void Insert();
void Solve();

int main(void) { // DP
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie();

	Insert();
	Solve();

	return 0;
}

void Insert() {
	cin >> n;
	int input;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}

	dp[0][0] = arr[0][0];
}

void Solve() {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + arr[i][j]; // 삼각형의 가장 왼쪽 부분은 상우 부분만 더하기
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j]; // 삼각형의 가장 오른쪽 부분은 상좌 부분만 더하기
			}
			else {
				dp[i][j] = dp[i - 1][j] + arr[i][j] < dp[i - 1][j - 1] + arr[i][j] ? dp[i - 1][j - 1] + arr[i][j] : dp[i - 1][j] + arr[i][j]; // 삼각형의 상좌, 상우 중 큰 수 저장
			}
		}
	}

	cout << *max_element(begin(dp[n - 1]), end(dp[n - 1]));
}