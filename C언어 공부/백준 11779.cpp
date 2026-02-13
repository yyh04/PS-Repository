#define INF 999999999
#include <iostream>
#include <queue>

using namespace std;

int route[1000][1000][2];
int path[1000];
int n, m;
int start, goal;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Init() {
	fill(&route[0][0][0], &route[999][999][2], INF);
	cin >> n >> m;

	int fst, snd, cost;

	for (int i = 0; i < m; i++) {
		cin >> fst >> snd >> cost;
		
		if (route[fst][snd][0] > cost) {
			route[fst][snd][0] = cost;
		}
	}

	cin >> start >> goal;

	for (int i = 0; i < n; i++) {
		route[i][i][0] = 0;
	}
}
 
void PathSearch(int _station) {
	for (int i = 0; i < n; i++) {
		if (route[_station][i][0] != INF){
			if (route[start][i][0] > route[start][_station][0] + route[_station][i][0]) {
				route[start][i][0] = route[start][_station][0] + route[_station][i][0];
				route[start][i][1] = _station;
				pq.push({ route[start][i][0], i });
			}
		}
	}
}

void 

void Solve() {
	for (int i = 0; i < n; i++) {
		if (route[start][i][0] != INF) {
			pq.push({ route[start][i][0], i });
		}
	}

	int searchIdx;

	while (!pq.empty()) {
		searchIdx = pq.top().second;
		pq.pop();
		PathSearch(searchIdx);
	}
}

void Print() {
	cout << route[start][goal] << '\n';
	cout << 
}

int main(void) {
	return 0;
}