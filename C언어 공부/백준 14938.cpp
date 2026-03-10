#include <iostream>
#include <queue>
#include <algorithm>
#define INF 999999999

using namespace std;

int n, m, r;
int itemCnt[101];
int graph[101][101];
int ans;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;
	int from, to;
	fill(&graph[0][0], &graph[100][101], INF);

	cin >> n >> m >> r;

	for (int i = 0; i <= n; i++) {
		graph[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> input;
		itemCnt[i] = input;
	}

	for (int i = 0; i < r; i++) {
		cin >> from >> to >> input;
		if (graph[from][to] > input) {
			graph[from][to] = input;
			graph[to][from] = input;
		}
		if (graph[to][from] > input) {
			graph[from][to] = input;
			graph[to][from] = input;
		}
	}
}

void Dijkstra(int _from) {
	for (int stopover = 1; stopover <= n; stopover++) {
		if (graph[_from][stopover] != INF) {
			pq.push({ graph[_from][stopover], stopover });
		}
	}

	while (!pq.empty()) {
		for (int to = 1; to <= n; to++) {
			if (graph[_from][to] > pq.top().first + graph[pq.top().second][to]) {
				graph[_from][to] = pq.top().first + graph[pq.top().second][to];
				graph[to][_from] = graph[_from][to];
				//cout << _from << "에서 " << to << "로 가는 경로 갱신 ...... 거리: " << graph[to][_from] << " ...... 경유지: " << pq.top().second << '\n';
				pq.push({ graph[_from][to], to });
			}
		}
		pq.pop();
	}
}

void Solve() {
	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
	}

	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] < m) {
				tmp += itemCnt[j];
			}
		}
		ans = ans < tmp ? tmp : ans;
	}

	cout << ans;
}

//void Print() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << graph[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}

int main(void) {
	Init();
	Solve();
	//Print();
	return 0;
}