#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];
int visitied[50][50];
int howManyBFS = 0;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void DFS(int, int);

int main(void) {

	int t;
	cin >> t;

	vector<int> warm;

	for (int i = 0; i < t; i++) {

		fill(&map[0][0], &map[50][50], 0);
		fill(&visitied[0][0], &visitied[50][50], 0);
		howManyBFS = 0;

		int m, n, k;
		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {

			int a, b;
			cin >> a >> b;

			map[b][a] = 1;

		}

		for (int r = 0; r < n; r++) {

			for (int c = 0; c < m; c++) {

				if (map[r][c] == 1 && visitied[r][c] == false) {

					DFS(r, c);
					howManyBFS++;

				}

			}

		}

		warm.push_back(howManyBFS);

	}

	for (int i = 0; i < warm.size(); i++) {

		cout << warm[i] << '\n';

	}

	return 0;

}

void DFS(int r, int c) {

	if (visitied[r][c]) {

		return;

	}

	visitied[r][c] = true;

	for (int i = 0; i < 4; i++) {

		int nr = r + dr[i];
		int nc = c + dc[i];

		if (0 <= nr && 0 <= nc && nr <= 49 && nc <= 49 && !visitied[nr][nc] && map[nr][nc]) {

			DFS(nr, nc);

		}

	}

}