
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int r, c, t;
int ans = 0;
int space[51][51];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

pair<pair<int, int>, pair<int, int>> airconPos;
pair<int, int> circleArr[51][51];
vector<pair<int, int>> dustPos;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;
	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> input;
			space[i][j] = input;

			if (input == -1) {
				airconPos.second = { i, j };
			}
			else if (input > 0) {
				ans += input;
				dustPos.push_back({ i, j });
			}
		}
	}

	airconPos.first = { airconPos.second.first - 1, airconPos.second.second };

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if ((i == 1 || i == r) && (2 <= j && j <= c)) {
				circleArr[i][j] = { 0, -1 };
			}
			else if ((i == airconPos.first.first || i == airconPos.second.first) && (2 <= j && j <= c - 1)) {
				circleArr[i][j] = { 0, 1 };
			}
			else if (((2 <= i && i <= airconPos.first.first) && (j == c)) || ((airconPos.second.first + 2 <= i && i <= r) && (j == 1))) {
				circleArr[i][j] = { -1, 0 };
			}
			else if (((1 <= i && i <= airconPos.first.first - 2) && j == 1) || ((airconPos.second.first <= i && i <= r - 1) && j == c)) {
				circleArr[i][j] = { 1, 0 };
			}
			else {
				circleArr[i][j] = { 0, 0 };
			}
		}
	}
}

bool IsInRange(int _r, int _c) {
	if (1 <= _r && _r <= r && 1 <= _c && _c <= c) {
		return true;
	}
	else {
		return false;
	}
}

void Diffuse() {
	int spaceTmp[51][51] = { 0, };
	spaceTmp[airconPos.first.first][airconPos.first.second] = -1;
	spaceTmp[airconPos.second.first][airconPos.second.second] = -1;

	for (int i = 0; i < dustPos.size(); i++) {
		int diffuseAreaCnt = 0;
		int curDustPosR = dustPos[i].first;
		int curDustPosC = dustPos[i].second;

		if (!IsInRange(curDustPosR, curDustPosC)) {
			continue;
		}

		int diffuseAmt = space[curDustPosR][curDustPosC] / 5;

		if (diffuseAmt <= 0) {
			spaceTmp[curDustPosR][curDustPosC] += space[curDustPosR][curDustPosC];
			continue;
		}


		for (int j = 0; j < 4; j++) {
			int nextDustPosR = curDustPosR + dr[j];
			int nextDustPosC = curDustPosC + dc[j];

			if (!IsInRange(nextDustPosR, nextDustPosC) || space[nextDustPosR][nextDustPosC] == -1) {
				continue;
			}

			spaceTmp[nextDustPosR][nextDustPosC] += diffuseAmt;
			diffuseAreaCnt++;
		}

		spaceTmp[curDustPosR][curDustPosC] += space[curDustPosR][curDustPosC] - (diffuseAmt * diffuseAreaCnt);
	}

	memcpy(space, spaceTmp, sizeof(spaceTmp));
}

void Circulate() {
	int spaceTmp[51][51] = { 0, };
	spaceTmp[airconPos.first.first][airconPos.first.second] = -1;
	spaceTmp[airconPos.second.first][airconPos.second.second] = -1;
	dustPos.clear();
	ans -= (space[airconPos.first.first - 1][1] + space[airconPos.second.first + 1][1]);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if ((i == (airconPos.first.first - 1) && j == 1) || (i == (airconPos.second.first + 1) && j == 1)) {
				continue;
			}
			if (space[i][j] > 0) {
				dustPos.push_back({ i + circleArr[i][j].first, j + circleArr[i][j].second });
			}

			spaceTmp[i + circleArr[i][j].first][j + circleArr[i][j].second] = space[i][j];
		}
	}

	spaceTmp[airconPos.first.first][airconPos.first.second + 1] = 0;
	spaceTmp[airconPos.second.first][airconPos.second.second + 1] = 0;
	memcpy(space, spaceTmp, sizeof(spaceTmp));
}

void Solve() {
	Init();

	for (int i = 0; i < t; i++) {
		Diffuse();
		Circulate();
	}

	cout << ans << '\n';
}

int main(void) {
	Solve();
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int r, c, t;
int ans = 0;
int space[51][51];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

pair<pair<int, int>, pair<int, int>> airconPos;
pair<int, int> circleArr[51][51];
vector<pair<int, int>> dustPos;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;
	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> input;
			space[i][j] = input;

			if (input == -1) {
				airconPos.second = { i, j };
			}
			else if (input > 0) {
				ans += input;
				dustPos.push_back({ i, j });
			}
		}
	}

	airconPos.first = { airconPos.second.first - 1, airconPos.second.second };

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if ((i == 1 || i == r) && (2 <= j && j <= c)) {
				circleArr[i][j] = { 0, -1 };
			}
			else if ((i == airconPos.first.first || i == airconPos.second.first) && (2 <= j && j <= c - 1)) {
				circleArr[i][j] = { 0, 1 };
			}
			else if (((2 <= i && i <= airconPos.first.first) && (j == c)) || ((airconPos.second.first + 2 <= i && i <= r) && (j == 1))) {
				circleArr[i][j] = { -1, 0 };
			}
			else if (((1 <= i && i <= airconPos.first.first - 2) && j == 1) || ((airconPos.second.first <= i && i <= r - 1) && j == c)) {
				circleArr[i][j] = { 1, 0 };
			}
			else {
				circleArr[i][j] = { 0, 0 };
			}
		}
	}

	
	cout << '\n';
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << "< " << circleArr[i][j].first << ", " << circleArr[i][j].second << " > ";
		}
		cout << '\n';
	}
	
}

bool IsInRange(int _r, int _c) {
	if (1 <= _r && _r <= r && 1 <= _c && _c <= c) {
		return true;
	}
	else {
		return false;
	}
}

void Print() {
	cout << '\n';
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << space[i][j] << ' ';
		}
		cout << '\n';
	}
}

void Diffuse() {
	int spaceTmp[51][51] = { 0, };
	spaceTmp[airconPos.first.first][airconPos.first.second] = -1;
	spaceTmp[airconPos.second.first][airconPos.second.second] = -1;

	for (int i = 0; i < dustPos.size(); i++) {
		int diffuseAreaCnt = 0;
		int curDustPosR = dustPos[i].first;
		int curDustPosC = dustPos[i].second;

		if (!IsInRange(curDustPosR, curDustPosC)) {
			continue;
		}

		int diffuseAmt = space[curDustPosR][curDustPosC] / 5;

		
		cout << "(" << curDustPosR << ", " << curDustPosC << ") " << space[curDustPosR][curDustPosC] << "확산\n";
		

		if (diffuseAmt <= 0) {
			spaceTmp[curDustPosR][curDustPosC] += space[curDustPosR][curDustPosC];
			continue;
		}
		

		for (int j = 0; j < 4; j++) {
			int nextDustPosR = curDustPosR + dr[j];
			int nextDustPosC = curDustPosC + dc[j];

			if (!IsInRange(nextDustPosR, nextDustPosC) || space[nextDustPosR][nextDustPosC] == -1) {
				continue;
			}

			spaceTmp[nextDustPosR][nextDustPosC] += diffuseAmt;
			diffuseAreaCnt++;
		}

		spaceTmp[curDustPosR][curDustPosC] += space[curDustPosR][curDustPosC] - (diffuseAmt * diffuseAreaCnt);

		
		cout << "(" << curDustPosR << ", " << curDustPosC << "): " << space[curDustPosR][curDustPosC] - (diffuseAmt * diffuseAreaCnt) << "만큼 남음\n";
	}

	memcpy(space, spaceTmp, sizeof(spaceTmp));
	cout << "\nDiffuse()\n";
	Print();
}

void Circulate() {
	int spaceTmp[51][51] = { 0, };
	spaceTmp[airconPos.first.first][airconPos.first.second] = -1;
	spaceTmp[airconPos.second.first][airconPos.second.second] = -1;
	dustPos.clear();
	ans -= (space[airconPos.first.first - 1][1] + space[airconPos.second.first + 1][1]);
	cout << "\nCirculate()\n";
	
	cout << "정화된 공기의 양 : " << space[airconPos.first.first - 1][1] + space[airconPos.second.first + 1][1] << "\n현재 ans = " << ans << '\n';
	

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if ((i == (airconPos.first.first - 1) && j == 1) || (i == (airconPos.second.first + 1) && j == 1)) {
				continue;
			}
			if (space[i][j] > 0) {
				dustPos.push_back({ i + circleArr[i][j].first, j + circleArr[i][j].second });
			}

			spaceTmp[i + circleArr[i][j].first][j + circleArr[i][j].second] = space[i][j];
		}
	}

	spaceTmp[airconPos.first.first][airconPos.first.second + 1] = 0;
	spaceTmp[airconPos.second.first][airconPos.second.second + 1] = 0;
	memcpy(space, spaceTmp, sizeof(spaceTmp));

	Print();
}

void Solve() {
	Init();

	for (int i = 0; i < t; i++) {
		Diffuse();
		Circulate();
	}

	cout << ans << '\n';
}

int main(void) {
	Solve();
	return 0;
}

*/