#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int, int);

vector<int> cnt;

bool map[26][26] = { 0, };
bool visitied[26][26] = { 0, };

int n = 0;
int counting = 0;
int howManyBFS = 0;

int dr[4] = { -1, 1, 0, 0 }; // »óÇÏÁÂ¿ì
int dc[4] = { 0, 0, -1, 1 };

int main(void) {

	string num;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> num;

		for (int j = 0; j < n; j++) {

			if (num[j] == '1') {

				map[i + 1][j + 1] = 1;

			}

		}

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (map[i + 1][j + 1] == 1 && visitied[i + 1][j + 1] == false) {

				BFS(i + 1, j + 1);
				howManyBFS++;
				cnt.push_back(counting);
				counting = 0;

			}

		}

	}

	sort(cnt.begin(), cnt.end());

	cout << howManyBFS << '\n';
	
	for (int i = 0; i < howManyBFS; i++) {

		cout << cnt[i] << '\n';

	}

	return 0;

}

void BFS(int fst, int snd) {

	queue<pair<int, int>> q;
	q.push({ fst, snd });
	visitied[fst][snd] = true;
	counting++;

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nr = r + dr[i];
			int nc = c + dc[i];

			if (1 <= nr && 1 <= nc && nr <= n && nc <= n && !visitied[nr][nc] && map[nr][nc] == 1) {

				q.push({ nr, nc });
				visitied[nr][nc] = true;
				counting++;

			}

		}

	}

}