#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visit[10][10];
bool visitCpy[10][10];

int n, m;
int lab[10][10];
int wallDr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int wallDc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int virusDr[4] = { 1, 0, -1, 0 };
int virusDc[4] = { 0, 1, 0, -1 };
int zeroCnt = 0;
int safeZoneCnt = 0;
int ans = 0;

//int example[3];

vector<pair<int, int>> virusVec;
queue<pair<int, int>> virusQue;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			lab[i][j] = input;

			if (input == 0) {
				zeroCnt++;
			}
			else if (input == 1) {
				visit[i][j] = true;
			}
			else if (input == 2) {
				virusVec.push_back({ i, j });
				visit[i][j] = true;
			}
		}
	}

	for (int i = 0; i <= n + 1; i++) {
		lab[i][0] = 1;
		lab[i][m + 1] = 1;
		visit[i][0] = true;
		visit[i][m + 1] = true;
	}

	for (int j = 0; j <= m + 1; j++) {
		lab[0][j] = 1;
		lab[n + 1][j] = 1;
		visit[0][j] = true;
		visit[n + 1][j] = true;
	}
}

// 벽을 세울만한 곳인지 확인
bool IsWallValue(int __fst, int __snd, int __trd) {
	int cnt[3] = { 0, 0, 0 };

	for (int i = 0; i < 8; i++) {
		if (cnt[0] >= 2) {
			cnt[0] = 10;
			break;
		}
		if (lab[((__fst - 1) / m) + 1 + wallDr[i]][(__fst % m == 0 ? m : __fst % m) + wallDc[i]] == 1) {
			cnt[0]++;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (cnt[1] >= 2) {
			cnt[1] = 10;
			break;
		}
		if (lab[((__snd - 1) / m) + 1 + wallDr[i]][(__snd % m == 0 ? m : __snd % m) + wallDc[i]] == 1) {
			cnt[1]++;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (cnt[2] >= 2) {
			cnt[2] = 10;
			break;
		}
		if (lab[((__trd - 1) / m) + 1 + wallDr[i]][(__trd % m == 0 ? m : __trd % m) + wallDc[i]] == 1) {
			cnt[2]++;
		}
	}

	if (cnt[0] == 10 && cnt[1] == 10 && cnt[2] == 10) {
		return true;
	}
	else {
		return false;
	}

}

int BFS() {
	int newVirusCnt = 0;
	virusQue = queue<pair<int, int>>();

	for (int i = 0; i < virusVec.size(); i++) {
		virusQue.push({ virusVec[i] });
	}

	while (!virusQue.empty()) {
		int nextR;
		int nextC;

		for (int i = 0; i < 4; i++) {
			nextR = virusQue.front().first + virusDr[i];
			nextC = virusQue.front().second + virusDc[i];
			
			if (1 <= nextR && nextR <= n && 1 <= nextC && nextC <= m && visitCpy[nextR][nextC] == false) {
				visitCpy[nextR][nextC] = true;
				newVirusCnt++;
				virusQue.push({nextR, nextC});
			}
		}

		virusQue.pop();
	}

	return newVirusCnt;
}

// 벽 3개 위치 고르기
void ChooseWall(int _fst, int _snd, int _trd) {
	memcpy(visitCpy, visit, sizeof(visit));

	lab[((_fst - 1) / m) + 1][_fst % m == 0 ? m : _fst % m] = 1;
	lab[((_snd - 1) / m) + 1][_snd % m == 0 ? m : _snd % m] = 1;
	lab[((_trd - 1) / m) + 1][_trd % m == 0 ? m : _trd % m] = 1;
	visitCpy[((_fst - 1) / m) + 1][_fst % m == 0 ? m : _fst % m] = true;
	visitCpy[((_snd - 1) / m) + 1][_snd % m == 0 ? m : _snd % m] = true;
	visitCpy[((_trd - 1) / m) + 1][_trd % m == 0 ? m : _trd % m] = true;

	if (IsWallValue(_fst, _snd, _trd)) {
		safeZoneCnt = zeroCnt - 3 - BFS();
		//if (ans < safeZoneCnt) {
		//	example[0] = _fst;
		//	example[1] = _snd;
		//	example[2] = _trd;
		//}
		ans = ans < safeZoneCnt ? safeZoneCnt : ans;
	}

	lab[((_fst - 1) / m) + 1][_fst % m == 0 ? m : _fst % m] = 0;
	lab[((_snd - 1) / m) + 1][_snd % m == 0 ? m : _snd % m] = 0;
	lab[((_trd - 1) / m) + 1][_trd % m == 0 ? m : _trd % m] = 0;
}

void Solve() {
	int lastIdx = n * m;

	for (int i = 1; i <= lastIdx; i++) {
		if (lab[((i - 1) / m) + 1][i % m == 0 ? m : i % m] != 0)
			continue;

		for (int j = i + 1; j <= lastIdx; j++) {
			if (lab[((j - 1) / m) + 1][j % m == 0 ? m : j % m] != 0)
				continue;

			for (int k = j + 1; k <= lastIdx; k++) {
				if (lab[((k - 1) / m) + 1][k % m == 0 ? m : k % m] != 0)
					continue;

				ChooseWall(i, j, k);
			}
		}
	}

	cout << ans;
}


int main(void) {
	Init();
	Solve();
	return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int lab[10][10];
//bool virusVisit[10][10];
//bool wallVisit[10][10];
//vector<pair<int, int>> virus;
//vector<pair<int, int>> wall;
//int n, m;
//
//void Init() {
//	ios::sync_with_stdio(false);
//	cout.tie(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	int input;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> input;
//			lab[i][j] = input;
//
//			if (input == 1) {
//				wall.push_back({ i, j });
//				wallVisit[i][j] = true;
//			}
//			if (input == 2) {
//				virus.push_back({ i, j });
//				virusVisit[i][j] = true;
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++) {
//		lab[0][i] = 1;
//		lab[9][i] = 1;
//		lab[i][0] = 1;
//		lab[i][9] = 1;
//	}
//}
//
//void SetWall() {
//}
//
//int main(void) {
//
//	return 0;
//}