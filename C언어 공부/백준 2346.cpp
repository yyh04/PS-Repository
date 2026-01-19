#include <iostream>
#include <deque>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	deque<pair<int, int>> dq;
	int n;
	cin >> n;

	int num;

	for (int i = 0; i < n; i++) {

		cin >> num;
		dq.push_back({ num, i + 1 });

	}

	int fst, snd;

	while (true) {

		fst = dq.front().first;
		snd = dq.front().second;

		cout << snd << ' ';
		dq.pop_front();

		if (dq.empty()) {

			break;

		}

		if (fst > 0) {

			for (int i = 0; i < fst - 1; i++) {

				dq.push_back(dq.front());
				dq.pop_front();

			}

		}

		else {

			for (int i = 0; i > fst; i--) {

				dq.push_front(dq.back());
				dq.pop_back();

			}

		}

	}

	return 0;

}