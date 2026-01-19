#include <iostream>

using namespace std;

bool visit[26] = { false, };
char map[20][20] = { 0, };
int ans;
int r, c;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void Init() {
	cin >> r >> c;
	char alpha;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> alpha;
			map[i][j] = alpha;
		}
	}
}

bool isInArea(int nr, int nc) {
	if (0 <= nr && nr < r && 0 <= nc && nc < c) {
		return true;
	}
	return false;
}

void DFS(int sr, int sc, int cnt) {
	ans = cnt > ans ? cnt : ans;
	visit[map[sr][sc] - 'A'] = true;
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = sr + dr[i];
		nc = sc + dc[i];
		if (isInArea(nr, nc) == true && visit[map[nr][nc] - 'A'] == false) {
			DFS(nr, nc, cnt + 1);
		}
	}
	visit[map[sr][sc] - 'A'] = false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	DFS(0, 0, 1);
	cout << ans;
	return 0;
}