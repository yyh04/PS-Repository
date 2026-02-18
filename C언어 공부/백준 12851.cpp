#include <iostream>

using namespace std;

int n, k;
int sec[100001];
int cnt[100001];

void Init() {
	cin >> n >> k;
}

void Search(int _cur, int _sec, int _type) {
	if (_cur < 0 || 100000 < _cur) {
		return;
	}

	if (sec[_cur] != 0) {
		if (sec[_cur] == _sec) {
			cnt[_cur]++;
		}
		else if (sec[_cur] < _sec) {
			return;
		}
		return;
	}
	else if (sec[_cur] == 0) {
		sec[_cur] = _sec;
	}

	if()

	if (_cur == k) {
		if (secMin > _sec) {
			secMin = _sec;
			cnt = 1;
		}
		else if (secMin == _sec) {
			cnt++;
		}

		return;
	}

	if (_cur == 0) {
		Search(_cur + 1, _sec + 1, 1);
	}
	else if (_type == -1) {
		Search(_cur * 2, _sec + 1, 0);
		Search(_cur - 1, _sec + 1, -1);
	}
	else if (_type == 1) {
		Search(_cur * 2, _sec + 1, 0);
		Search(_cur + 1, _sec + 1, 1);
	}
	else if (_type == 0) {
		Search(_cur * 2, _sec + 1, 0);
		Search(_cur - 1, _sec + 1, -1);
		Search(_cur + 1, _sec + 1, 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	Init();
	Search(n, 0, 0);
	cout << secMin << '\n' << cnt;

	return 0;
}