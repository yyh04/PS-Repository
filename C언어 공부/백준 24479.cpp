#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr[100001];
int visitied[100001] = { 0, };
int order[100001] = { 0, };
int cnt = 0;

void DFS(int);

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {

		int from, to;
		cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);

	}

	for (int i = 0; i <= n; i++) {

		sort(arr[i].begin(), arr[i].end());

	}

	DFS(start);

	for (int i = 1; i <= n; i++) {

		cout << order[i] << '\n';

	}

	return 0;

}

void DFS(int start) {

	if (visitied[start]) {

		return;

	}

	visitied[start] = true;
	cnt++;
	order[start] = cnt;

	for (int i = 0; i < arr[start].size(); i++) {

		int y = arr[start][i];
		DFS(y);

	}

}