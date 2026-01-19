#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int, int);

int map[100][100] = { 0, };
int visitied[100][100] = { 0, };
int dist[100][100] = { 0, };
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int n, m;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;

	string trueOrFalse;

	for (int r = 0; r < n; r++) {

		cin >> trueOrFalse;

		for (int c = 0; c < m; c++) {

			if (trueOrFalse[c] == '1') {

				map[r][c] = 1;

			}

		}

	}

	cout << BFS(0, 0);

	return 0;

}

int BFS(int r, int c) {

	queue<pair<int, int>> q;

	q.push({ r, c });
	visitied[r][c] = true;
	dist[r][c] = 1;

	while (!q.empty()) {

		int fst = q.front().first;
		int snd = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nr = fst + dr[i];
			int nc = snd + dc[i];

			if (0 <= nr && 0 <= nc && nr <= 99 && nc <= 99 && !visitied[nr][nc] && map[nr][nc]) {

				q.push({ nr, nc });

				visitied[nr][nc] = true;
				dist[nr][nc] = dist[fst][snd] + 1;

			}

		}

	}

	return dist[n - 1][m - 1];

}