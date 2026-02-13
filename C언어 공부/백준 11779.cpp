#define INF 999999999
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int route[1001][1001];
int trackArr[1001];
int n, m;
int start, goal;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
stack<int> st;

void Init() {
	fill(&route[0][0], &route[1000][1001], INF);
	cin >> n >> m;

	int fst, snd, cost;

	for (int i = 1; i <= m; i++) {
		cin >> fst >> snd >> cost;
		
		if (route[fst][snd] > cost) {
			route[fst][snd] = cost;
		}
	}

	cin >> start >> goal;

	for (int i = 1; i <= n; i++) {
		route[i][i] = 0;
	}
}
 
void PathSearch(int _station) {
	for (int i = 1; i <= n; i++) {
		if (route[_station][i] != INF && route[start][_station] != INF) {
			if (route[start][i] > route[start][_station] + route[_station][i]) {
				route[start][i] = route[start][_station] + route[_station][i];
				trackArr[i] = _station;
				pq.push({ route[start][i], i });
			}
		}
	}
}

void Dijkstra() {
	for (int i = 1; i <= n; i++) {
		if (route[start][i] != INF) {
			pq.push({ route[start][i], i });
			trackArr[i] = start;
		}
	}

	int searchIdx;

	while (!pq.empty()) {
		searchIdx = pq.top().second;
		pq.pop();
		PathSearch(searchIdx);
	}
}

void OrganizePath() {
	int cur = trackArr[goal];
	st.push(goal);
	st.push(cur);
	while (cur != start) {
		cur = trackArr[cur];
		st.push(cur);
	}
}

void Print() {
	cout << route[start][goal] << '\n';

	cout << st.size() << '\n';

	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}

//void Debug() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << route[i][j][0] << ' ';
//		}
//		cout << '\n';
//	}
//}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	Init();
	Dijkstra();
	OrganizePath();
	//Debug();
	Print();

	return 0;
}