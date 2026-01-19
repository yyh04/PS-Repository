#include <iostream>
#include <queue>

using namespace std;

void BFS();

queue<int> q;

int map[101] = { 0, };
int counting[101] = { 0, };
bool visitied[101] = { 0, };

int ladder, snake;
int dp[6] = { 1,2,3,4,5,6 };

int main(void) {

	cin >> ladder >> snake;

	for (int i = 0; i < ladder; i++) {

		int from, to;
		cin >> from >> to;

		map[from] = to;

	}

	for (int i = 0; i < snake; i++) {

		int from, to;
		cin >> from >> to;

		map[from] = to;

	}

	BFS();

	cout << counting[100] << '\n';

	return 0;

}

void BFS() {

	q.push(1);
	visitied[1] = true;

	while (!q.empty()) {

		int currentPos = q.front();

		q.pop();

		for (int i = 0; i < 6; i++) {

			int nextPos = currentPos + dp[i];

			if (1 <= nextPos && nextPos <= 100 && !visitied[nextPos]) {

				visitied[nextPos] = true;
				counting[nextPos] = counting[currentPos] + 1;

				if (map[nextPos] != 0 && !visitied[map[nextPos]]) {

					q.push(map[nextPos]);
					visitied[map[nextPos]] = true;
					counting[map[nextPos]] = counting[currentPos] + 1;

				}

				else if (map[nextPos] == 0) {

					q.push(nextPos);

				}

			}

		}

	}

	return;

}