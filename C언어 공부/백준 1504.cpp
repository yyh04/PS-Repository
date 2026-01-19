#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int map[801][801];
int n, e;
int v1, v2;

void Init() {
	cin >> n >> e;
	fill(&map[0][0], &map[n][n], INF);
	for (int i = 0; i < e; i++) {
		int ver1, ver2, cost;
		cin >> ver1 >> ver2 >> cost;
		map[ver1][ver2] = cost;
		map[ver2][ver1] = cost;
	}
	for (int i = 1; i <= n; i++) {
		map[i][i] = 0;
	}
	cin >> v1 >> v2;
}

int Dijkstra(int fst, int snd) {
	int* arr = new int[n + 1]();
	bool* visit = new bool[n + 1]();
	for (int i = 1; i <= n; i++) {
		arr[i] = map[fst][i];
		if (map[fst][i] != INF) {
			pq.push({ map[fst][i], i });
		}
	}
	int cst;
	int idx;
	while (!pq.empty()) {
		cst = pq.top().first;
		idx = pq.top().second;
		pq.pop();
		if (visit[idx] == true) {
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (map[idx][i] != INF) {
				if (arr[i] > cst + map[idx][i]) {
					arr[i] = cst + map[idx][i];
					pq.push({ arr[i], i });
				}
			}
			visit[idx] = true;
		}
	}
	int rtn = arr[snd];
	delete[] arr;
	delete[] visit;
	return rtn;
}

void Solve() {
	int r1, r2, r3;
	int ans1 = INF, ans2 = INF;
	bool flag1 = false, flag2 = false;
	r1 = Dijkstra(1, v1);
	if (r1 >= INF) {
		flag1 = true;
	}
	r2 = Dijkstra(v1, v2);
	if (r2 >= INF) {
		flag1 = true;
		flag2 = true;
	}
	r3 = Dijkstra(v2, n);
	if (r3 >= INF) {
		flag1 = true;
	}
	if (flag1 == false) {
		ans1 = r1 + r2 + r3;
	}
	r1 = Dijkstra(1, v2);
	if (r1 >= INF) {
		flag2 = true;
	}
	r3 = Dijkstra(v1, n);
	if (r3 >= INF) {
		flag2 = true;
	}
	if (flag2 == false) {
		ans2 = r1 + r2 + r3;
	}
	if (ans1 > ans2) {
		if (flag2 == true) {
			cout << -1;
		}
		else {
			cout << ans2;
		}
	}
	else if (ans1 == ans2){
		if (flag1 == true && flag2 == true) {
			cout << -1;
		}
		else {
			cout << ans1;
		}
	}
	else if (ans1 < ans2) {
		if (flag1 == true) {
			cout << -1;
		}
		else {
			cout << ans1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	Solve();
	return 0;
}