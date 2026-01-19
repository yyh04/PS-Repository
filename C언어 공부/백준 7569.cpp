#include <iostream>
#include <queue>

using namespace std;

void BFS(void);

typedef struct position {

	int height;
	int row;
	int column;

}pos;

queue<pos> q;

int map[100][100][100] = { 0, };
int counting[100][100][100] = { 0, };
bool visitied[100][100][100] = { 0, };

int dh[6] = { 1, -1, 0, 0, 0, 0 }; // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dr[6] = { 0, 0, 0, 0, 1, -1 };
int dc[6] = { 0, 0, -1, 1, 0, 0 };

int m, n, h; // 가로, 세로, 높이

int main(void) {

	int max = 0;

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {

		for (int j = 0; j < n; j++) {

			for (int k = 0; k < m; k++) {

				cin >> map[i][j][k];

				if (map[i][j][k] == 1) {

					q.push({ i,j,k });
					visitied[i][j][k] = true;

				}

			}

		}

	}

	BFS();

	for (int i = 0; i < h; i++) {

		for (int j = 0; j < n; j++) {

			for (int k = 0; k < m; k++) {

				if (counting[i][j][k] == 0 && map[i][j][k] == 0) {

					cout << -1 << '\n';

					return 0;

				}

				if (max < counting[i][j][k]) {

					max = counting[i][j][k];

				}

			}

		}

	}

	if (max == 0) {

		cout << 0 << '\n';

	}

	else {

		cout << max << '\n';

	}

	return 0;

}

void BFS() {

	while (!q.empty()) {

		int currentHeight = q.front().height;
		int currentRow = q.front().row;
		int currentColumn = q.front().column;

		q.pop();

		for (int i = 0; i < 6; i++) {

			int nextHeight = currentHeight + dh[i];
			int nextRow = currentRow + dr[i];
			int nextColumn = currentColumn + dc[i];

			if (0 <= nextHeight && 0 <= nextRow && 0 <= nextColumn && nextHeight < h && nextRow < n && nextColumn < m && !visitied[nextHeight][nextRow][nextColumn] && map[nextHeight][nextRow][nextColumn] == 0) {

				q.push({ nextHeight, nextRow, nextColumn });
				visitied[nextHeight][nextRow][nextColumn] = true;
				counting[nextHeight][nextRow][nextColumn] = counting[currentHeight][currentRow][currentColumn] + 1;

			}

		}

	}

	return;

}