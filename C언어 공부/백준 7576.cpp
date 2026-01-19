#include <iostream>
#include <queue>

using namespace std;

void BFS();

queue<pair<int,int>> q;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int map[1001][1001] = { 0, };
int counting[1001][1001] = { 0, };
bool visitied[1001][1001] = { 0, };

int rowNum;
int columnNum;

int main(void) {

	cin >> columnNum >> rowNum;
	int max = 0;

	for (int i = 0; i < rowNum; i++) {

		for (int j = 0; j < columnNum; j++) {

			cin >> map[i][j];

			if (map[i][j] == 1) {

				q.push({ i, j });

			}

		}

	}

	BFS();

	for (int i = 0; i < rowNum; i++) {

		for (int j = 0; j < columnNum; j++) {

			if (counting[i][j] == 0 && map[i][j] == 0) {

				cout << -1;

				return 0;

			}

			if (counting[i][j] > max) {

				max = counting[i][j];

			}

		}

	}

	if (max == 1) {

		cout << 0;

	}

	else {

		cout << max;

	}

	return 0;

}

void BFS() {

	visitied[q.front().first][q.front().second] = true;

	while (!q.empty()) {

		int currentRow = q.front().first;
		int currentColumn = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nextRow = currentRow + dr[i];
			int nextColumn = currentColumn + dc[i];

			if (0 <= nextRow && 0 <= nextColumn && nextRow < rowNum && nextColumn < columnNum && !visitied[nextRow][nextColumn] && map[nextRow][nextColumn] == 0) {

				q.push({ nextRow, nextColumn });

				visitied[nextRow][nextColumn] = true;
				counting[nextRow][nextColumn] = counting[currentRow][currentColumn] + 1;

			}

		}

	}

}