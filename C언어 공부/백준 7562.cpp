#include <iostream>
#include <queue>

using namespace std;

int BFS(pair<int, int>, pair<int, int>);

bool visitied[301][301];
int attempt[301][301];
int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int length;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		fill(&visitied[0][0], &visitied[300][300], 0);
		fill(&attempt[0][0], &attempt[300][300], 0);

		pair<int, int> start;
		pair<int, int> goal;
		cin >> length;
		cin >> start.first >> start.second;
		cin >> goal.first >> goal.second;

		cout << BFS(start, goal) << '\n';

	}

	return 0;

}

int BFS(pair<int, int> start, pair<int, int> goal) {

	queue<pair<int,int>> q;

	q.push(start);
	visitied[start.first][start.second] = true;

	while (!q.empty()) {

		int currentRow = q.front().first;
		int currentColumn = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {

			int nextRow = currentRow + dr[i];
			int nextColumn = currentColumn + dc[i];

			if (0 <= nextRow && 0 <= nextColumn && nextRow < length && nextColumn < length && !visitied[nextRow][nextColumn]) {

				q.push({ nextRow, nextColumn });

				visitied[nextRow][nextColumn] = true;
				attempt[nextRow][nextColumn] = attempt[currentRow][currentColumn] + 1;

			}

		}

	}

	return attempt[goal.first][goal.second];
	
}	