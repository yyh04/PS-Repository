#include <iostream>

using namespace std;

int n, m;
int lab[10][10];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			lab[i][j] = input;
		}
	}

	for (int i = 0; i < n; i++) {
		lab[i][0] = 1;
		lab[i][m + 1] = 1;
	}

	for (int j = 0; j < m; j++) {
		lab[0][j] = 1;
		lab[n + 1][j] = 1;
	}
}

// 64 => 8 8
// 59 => 8 3
// (n - 1) * i + j

// 벽을 세울만한 곳인지 확인
bool CheckWallValue(int __fst, int __snd, int __trd) {
	int cnt[3];
	for (int i = 0; i < 8; i++) {
		if(lab[][__fst / n])
	}
}

// 벽 3개 위치 고르기
void ChooseWall(int _fst, int _snd, int _trd) {
	
}


// 바이러스 퍼뜨리기

// 결과 갱신


int main(void) {

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