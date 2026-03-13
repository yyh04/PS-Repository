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
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
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
			}
			else if (input == 9) {
				sharkPos = { i, j };
			}
			aqua[i][j] = input;
		}
	}
}

bool IsInRange(int _r, int _c) {
	if (0 <= _r && _r < n && 0 <= _c && _c < n) {
		return true;
	}
	return false;
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << aqua[i][j] << ' ';
		}

		cout << '\n';
	}

	cout << '\n';
}

void BFS() { 
	bool visit[20][20] = { false, };

	queue<pair<pair<int, int>, int>> BFSQue;

	BFSQue.push({ sharkPos, 1 });
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
					aqua[sharkNextR][sharkNextC] = 9;
					aqua[sharkPos.first][sharkPos.second] = 0;
					sharkPos = { sharkNextR, sharkNextC };

					if (++sharkEatCnt >= sharkSize) {
						sharkSize++;
						sharkEatCnt = 0;
					}

					cout << "[" << sharkNextR + 1 << "]" << "[" << sharkNextC + 1 << "]" << ": 물고기 사냥" << '\n';
					cout << searchLevel << "만큼 이동함\n";
					cout << "sharkSize: " << sharkSize << '\n';
					cout << "sharkEatCnt: " << sharkEatCnt << '\n';
					cout << "상어의 현재 위치: [" << sharkPos.first + 1 << "][" << sharkPos.second + 1 << "]\n";
					cout << "timer: " << timer << '\n';
					cout << '\n';
					Print();

					return;
				}

				visit[sharkNextR][sharkNextC] = true;
				BFSQue.push({ {sharkNextR, sharkNextC}, searchLevel + 1 });
			}
		}
	}
	

	cout << timer << '\n';
	flag = true;
	cout << "\n먹을 수 있는 물고기를 찾을 수 없음\n";
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