#include <iostream>
#include <vector>

using namespace std; // 치즈 외부 공기: X, 치즈: 1, 치즈 내부 공기: 0

int n, m;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int deleteCnt = 0;
int cheeseCnt = 0;
char map[101][101];
bool cheeseVisit[101][101];
bool emptyVisit[101][101];
vector <pair<int, int>> cCheeseVec;

bool IsInRange(int _r, int _c) {
	if (0 <= _r && _r < n && 0 <= _c && _c < m) {
		return true;
	}
	else {
		return false;
	}
}

void FindEmpty(int _r, int _c) {
	cout << "FindEmpty called: " << _r << ' ' << _c << '\n';
	if (emptyVisit[_r][_c] == true || map[_r][_c] == '1' || !IsInRange(_r, _c)) {
		return;
	}

	emptyVisit[_r][_c] = true;
	map[_r][_c] = 'X';
	int nextR;
	int nextC;

	for (int i = 0; i < 4; i++) {
		nextR = _r + dr[i];
		nextC = _c + dc[i];
		FindEmpty(nextR, nextC);
	}
}

void Init() {
	cin >> n >> m;
	char input;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			map[i][j] = input;

			if(input == '1') {
				cheeseCnt++;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			FindEmpty(i * n, j);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			FindEmpty(i, j * m);
		}
	}

	cout << "Init complete\n";
}

void FindCCheese(int _r, int _c) {
	cout << "FindCCheese called: " << _r << ' ' << _c << '\n';
	if (cheeseVisit[_r][_c] == true || map[_r][_c] != '1' || !IsInRange(_r, _c)) {
		return;
	}

	cheeseVisit[_r][_c] = true;
	int nextR;
	int nextC;
	int emptyCnt = 0;

	for (int i = 0; i < 4; i++) {
		nextR = _r + dr[i];
		nextC = _c + dc[i];

		if (map[nextR][nextC] == 'X') {
			emptyCnt++;
		}

		FindCCheese(nextR, nextC);
	}

	if (emptyCnt >= 2) {
		cCheeseVec.push_back({_r, _c });
	}
}

void DeleteC() {
	cout << "DeleteC called\n";
	for (int i = 0; i < cCheeseVec.size(); i++) {
		map[cCheeseVec[i].first][cCheeseVec[i].second] = 'X';
		cheeseCnt--;
		FindEmpty(cCheeseVec[i].first, cCheeseVec[i].second);
	}

	deleteCnt++;
	cCheeseVec = vector<pair<int, int>>();
}

//void Print() {
//	for(int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << map[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	Init();

	while (cheeseCnt > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				FindCCheese(i, j);
			}
		}
		DeleteC();
	}

	cout << deleteCnt;
	//Print();
	return 0;
}