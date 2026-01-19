#include <iostream>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i * i <= n; i++) {

		cnt++;

	}

	cout << cnt;
	
	return 0;

}