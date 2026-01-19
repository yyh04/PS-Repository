#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int num;

	for (int i = 0; i < n; i++) {

		cin >> num;
		s.push(num);

	}

	int remainMoney = k;
	int cnt = 0;

	while (remainMoney) {

		if (remainMoney >= s.top()) {

			cnt += remainMoney / s.top();

		}

		remainMoney = remainMoney % s.top();
		s.pop();

	}

	cout << cnt << '\n';

	return 0;

}