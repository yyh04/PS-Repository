#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
char map[101][101];
bool cheeseVisit[101][101];
bool emptyVisit[101][101];
vector <pair<pair<int, int>, char>> cheeseVec;

void Init() {
	cin >> n >> m;
	char input;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			map[i][j] = input;
			if (input == '1') {
				cheeseVec.push_back({ { i, j }, NULL});
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
}

void FindEmpty(int _r, int _c) {
	if (emptyVisit[_r][_c] == true || map[_r][_c] == '1') {
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

void FindCheese(int _r, int _c) {
	if (cheeseVisit[_r][_c] == true || map[_r][_c] != '1') {
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
		FindCheese(nextR, nextC);
	}

	if (emptyCnt >= 2) {
		cheeseVec[{_r, _c}] = 'C';
	}
}

void DeleteC() {
	for (int i = 0; i < cheeseVec.size(); i++) {
	}
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
	//Print();

	return 0;
}