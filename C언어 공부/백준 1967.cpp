#include <iostream>
#include <vector>

using namespace std;

int n;
int maxi;
int tmp;
bool visit[10001];
vector<pair<int, int>> edge[10001];

void Init() {
	maxi = 0;
	int start, fin, weight;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> start >> fin >> weight;
		edge[start].push_back({ fin, weight });
		edge[fin].push_back({ start, weight });
	}
}

void BFS(int current, int sum) {
	visit[current] = true;
	if (maxi < sum) {
		maxi = sum;
		tmp = current;
	}
	for (int i = 0; i < edge[current].size(); i++) {
		if (visit[edge[current][i].first] == false) {
			BFS(edge[current][i].first, sum + edge[current][i].second);
		}
	}
	visit[current] = false;
}

void Solve() {
	Init();
	BFS(1, 0);
	maxi = 0;
	BFS(tmp, 0);
	cout << maxi;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Solve();
	return 0;
}