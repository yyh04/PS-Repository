#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int idx;
int route;
int sec[100001];
bool visit[100001];
queue<pair<int,int>> q;

void Init() {
	cin >> n >> k;
	idx = 1;
	fill(sec, sec + 100001, 999999999);
}

void Find(int _to, int _sec) {
	if (_to < 0 || 100000 < _to) {
		return;
	}

	if (sec[_to] < _sec) {
		return;
	}

	if (sec[_to] > _sec) {
		sec[_to] = _sec;
	}	

	if (_to == k && sec[_to] == _sec) {
		route++;
	}

	if (!visit[_to]) {
		q.push({ _to, _sec });																				
	}
}

void Search(int _cur, int _sec) {
	Find(_cur - 1, _sec);
	Find(_cur + 1, _sec);

	if (_cur != 0) {
		Find(_cur * 2, _sec);
	}

	visit[_cur] = true;
	idx++;
}

void Solve() {
	Search(n, idx); // ÃÊ±â Å½»ö

	while (!q.empty()) {
		Search(q.front().first, q.front().second + 1);
		q.pop();
	}
}

void Print() {
	if (n == k) {
		cout << 0 << '\n' << 1;
	}
	else {
		cout << sec[k] << '\n' << route;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	Init();
	Solve();
	Print();

	return 0;
}

/*
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
*/