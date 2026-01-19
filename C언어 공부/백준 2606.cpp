#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[101];
int visitied[101] = { 0, };
int cnt = 0;

void BFS(int);

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int from, to;
		cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);

	}

	for (int i = 0; i < n; i++) {

		sort(arr[i + 1].begin(), arr[i + 1].end());

	}

	BFS(1);

	cout << cnt;

}

void BFS(int start) {

	queue<int> q;

	q.push(start);
	visitied[start] = true;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			int y = arr[x][i];

			if (!visitied[y]) {

				q.push(y);
				visitied[y] = true;
				cnt++;

			}

		}

	}

}