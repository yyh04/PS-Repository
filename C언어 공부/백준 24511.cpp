#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> v;
deque<int> dq;

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

	for (int i = 0; i < v.size(); i++) {

		cin >> num;

		if (v[i] == 0) {

			dq.push_front(num);

		}

	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {

		cin >> num;
		dq.push_back(num);

	}

	for (int i = 0; i < m; i++) {

		cout << dq.front() << ' ';
		dq.pop_front();

	}

	return 0;

}