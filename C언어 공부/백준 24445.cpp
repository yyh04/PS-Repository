#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr[100001];
int visitied[100001] = { 0, };
int order[100001] = { 0, };
int cnt = 0;

bool Compare(int, int);
void BFS(int);

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {

		int from, to;
		cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);

	}

	for (int i = 1; i <= n; i++) {

		sort(arr[i].begin(), arr[i].end(), Compare);

	}

	BFS(r);

	for (int i = 0; i < n; i++) {

		cout << order[i + 1] << '\n';

	}


	return 0;

}

bool Compare(int fst, int snd) {

	return fst > snd;

}

void BFS(int start) {

	queue<int> q;
	q.push(start);
	visitied[start] = true;
	cnt++;
	order[start] = cnt;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			int y = arr[x][i];

			if (!visitied[y]) {

				q.push(y);
				visitied[y] = true;
				cnt++;
				order[y] = cnt;

			}

		}

	}

}