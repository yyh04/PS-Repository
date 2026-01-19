#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int ans = 1;

void Init() {
	cin >> n >> m;
}

void Solve(int r, int c, int cnt) {
	if (r % 2 == 1 || c % 2 == 1) {
		cout << ans;
		return;
	}
	ans += (int)pow(4, cnt + 1);
	Solve(r / 2, c / 2, cnt + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	if (n % 2 == 0 || m % 2 == 0) {
		cout << 0;
	}
	else {
		Solve(n / 2 + 1, m / 2 + 1, 0);
	}
	return 0;
}