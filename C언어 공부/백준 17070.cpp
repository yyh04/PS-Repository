#include <iostream>

using namespace std;

int n;
int ans = 0;
int house[20][20];

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			house[i][j] = input;
		}
	}
}

bool IsInRange(int _r, int _c) {
	if (1 <= _r && _r <= n && 1 <= _c && _c <= n) {
		return true;
	}
	else {
		return false;
	}
}

void Search(int _state, pair<int, int> _endPos) { // 1. width 2. length 3. diagonal
	
	if (!IsInRange(_endPos.first, _endPos.second)) {
		return;
	}

	if ((_state == 1 || _state == 2) && house[_endPos.first][_endPos.second] == 1) {
		return;
	}
	else if (_state == 3 && (house[_endPos.first][_endPos.second] == 1 || house[_endPos.first - 1][_endPos.second] == 1 || house[_endPos.first][_endPos.second - 1] == 1)) {
		return;
	}

	if (_endPos.first == n && _endPos.second == n) {
		ans++;
		return;
	}

	switch (_state) {
		case 1:
			Search(1, { _endPos.first, _endPos.second + 1 });
			Search(3, { _endPos.first + 1, _endPos.second + 1 });
			break;
		case 2:
			Search(2, { _endPos.first + 1, _endPos.second });
			Search(3, { _endPos.first + 1, _endPos.second + 1 });
			break;
		case 3:
			Search(1, { _endPos.first, _endPos.second + 1 });
			Search(2, { _endPos.first + 1, _endPos.second });
			Search(3, { _endPos.first + 1, _endPos.second + 1 });
			break;
	}
}

void Solve() {
	Search(1, { 1, 2 });
	cout << ans;
}

int main(void) {
	Init();
	Solve();

	return 0;
}