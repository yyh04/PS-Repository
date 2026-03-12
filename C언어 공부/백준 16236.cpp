#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999

using namespace std;

bool flag = false;
int n;
int timer;
int sharkSize = 2;
int sharkEatCnt = 0;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
int aqua[20][20];

pair<int, int> sharkPos;
vector<pair<int, int>> fishVec[7];

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input != 9 && input != 0) {
				fishVec[input].push_back({ i, j });
				aqua[i][j] = input;
			}
			else if (input == 9) {
				sharkPos = { i, j };
				aqua[i][j] = 0;
			}

		}
	}
}

bool IsInRange(int _r, int _c) {
	if (0 <= _r && _r < n && 0 <= _c && _c < n) {
		return true;
	}
	return false;
}

void BFS() { // 먹을 수 있는 물고기가 있는지, 가장 가까운 물고기, 가장 가까운 물고기까지 거리
	bool visit[20][20] = { false, };

	queue<pair<pair<int, int>, int>> BFSQue;

	BFSQue.push({ sharkPos, 0 });
	visit[sharkPos.first][sharkPos.second] = true;

	while (!BFSQue.empty()) {
		int sharkCurR = BFSQue.front().first.first;
		int sharkCurC = BFSQue.front().first.second;
		int searchLevel = BFSQue.front().second;
		BFSQue.pop();

		for (int i = 0; i < 4; i++) {
			int sharkNextR = sharkCurR + dr[i];
			int sharkNextC = sharkCurC + dc[i];

			if (IsInRange(sharkNextR, sharkNextC) && !visit[sharkNextR][sharkNextC] && aqua[sharkNextR][sharkNextC] <= sharkSize) {
				if (aqua[sharkNextR][sharkNextC] != 0 && aqua[sharkNextR][sharkNextC] != sharkSize) {
					timer += searchLevel;
					aqua[sharkNextR][sharkNextC] = 0;
					sharkPos = { sharkNextR, sharkNextC };

					if (++sharkEatCnt >= sharkSize) {
						sharkSize++;
						sharkEatCnt = 0;
					}

					cout << "물고기 사냥" << '\n';
					return;
				}

				visit[sharkNextR][sharkNextC] = true;
				BFSQue.push({ {sharkNextR, sharkNextC}, searchLevel + 1 });
			}
		}
	}
	

	cout << timer << '\n';
	flag = true;
}

void Solve() {
	while (flag == false) {
		BFS();
	}
}

int main(void) {
	Init();
	Solve();
	return 0;
}