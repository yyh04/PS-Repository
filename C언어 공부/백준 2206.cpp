#include <iostream>
#include <queue>

using namespace std;

int BFS();

struct statue {

	int row;
	int column;
	int broke;

};

queue<statue> q;

int map[1000][1000] = { 0, };
int visitied[1000][1000][2] = {0,};
int dr[4] = { -1, 1, 0 ,0 };
int dc[4] = { 0, 0, -1, 1 };

int n, m;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;

	char trueOrFalse;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cin >> trueOrFalse;
			map[i][j] = trueOrFalse - '0';

		}

	}

	cout << BFS();

	return 0;

}

int BFS() {

	q.push({ 0,0,0 });
	visitied[0][0][0] = 1;

	while (!q.empty()) {

		int currentR = q.front().row;
		int currentC = q.front().column;
		int currentB = q.front().broke;

		q.pop();

		if (currentR == n - 1 && currentC == m - 1) {

			return visitied[currentR][currentC][currentB];

		}

		for (int i = 0; i < 4; i++) {

			int nextR = currentR + dr[i];
			int nextC = currentC + dc[i];

			if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m) {

				if (map[nextR][nextC] == 1 && currentB == 0) {

					q.push({nextR, nextC, 1});
					visitied[nextR][nextC][1] = visitied[currentR][currentC][currentB] + 1;

				}

				else if (map[nextR][nextC] == 0 && !visitied[nextR][nextC][currentB]) {

					q.push({nextR, nextC, currentB});
					visitied[nextR][nextC][currentB] = visitied[currentR][currentC][currentB] + 1;

				}

			}

		}

	}

	return -1;

}