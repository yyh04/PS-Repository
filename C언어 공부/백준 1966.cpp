#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n, m;
	int rank;

	for (int i = 0; i < t; i++) {

		vector<int> v;
		queue<pair<int, bool>> q;

		cin >> n >> m;

		for (int j = 0; j < n; j++) {

			cin >> rank;
			v.push_back(rank);

			if (m == j) {

				q.push({ rank, true });

			}

			else {

				q.push({ rank, false });

			}

		}

		sort(v.begin(), v.end(), greater<int>());

		int order = 1;
		int key = 0;

		while (1) {

			if (v[key] == q.front().first) {

				if (q.front().second == true) {

					cout << order << '\n';
					break;

				}

				key++;
				order++;
				q.pop();

			}

			else {

				q.push(q.front());
				q.pop();

			}

		}

	}

	return 0;

}