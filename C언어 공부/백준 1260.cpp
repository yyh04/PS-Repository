#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr[1001];
int visitiedDFS[1001] = { 0, };
int visitiedBFS[1001] = { 0, };

void DFS(int);
void BFS(int);

int main(void) {
	
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {

		int from, to;
		cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);

	}

	for (int i = 0; i < n; i++) {

		sort(arr[i + 1].begin(), arr[i + 1].end());

	}

	DFS(r);
	cout << '\n';
	BFS(r);
	cout << '\n';

	return 0;

}

void DFS(int start) {

	if (visitiedDFS[start]) {

		return;

	}

	visitiedDFS[start] = true;

	cout << start << ' ';

	for (int i = 0; i < arr[start].size(); i++) {

		int x = arr[start][i];
		DFS(x);

	}

}

void BFS(int start) {

	queue<int> q;

	q.push(start);
	visitiedBFS[start] = true;

	cout << start << ' ';

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			int y = arr[x][i];

			if (!visitiedBFS[y]) {

				q.push(y);
				visitiedBFS[y] = true;

				cout << y << ' ';

			}

		}

	}

}