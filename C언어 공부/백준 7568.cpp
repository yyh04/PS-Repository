#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	int weight;
	int height;

	for (int i = 0; i < n; i++) {

		cin >> weight >> height;

		v.push_back({ weight, height });

	}

	int cnt = 1;

	for (int i = 0; i < n; i++) {

		cnt = 1;

		for (int j = 0; j < n; j++) {

			if (v[i].first < v[j].first && v[i].second < v[j].second) {

				cnt++;

			}

		}

		cout << cnt << ' ';

	}

	return 0;

}