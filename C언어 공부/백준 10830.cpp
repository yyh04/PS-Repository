#include <iostream>
#include <cstring>

using namespace std;

int n;
long long b;
long long ans[5][5];
long long temp[5][5];
long long arr[5][5];


void Init() {
	cin >> n >> b;
	long long input;

	for (int i = 0; i < n; i++) {
		ans[i][i] = 1;

		for (int j = 0; j < n; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}
}

void MatMul(long long _fst[5][5], long long _snd[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;

			for (int k = 0; k < n; k++) {
				temp[i][j] += (_fst[i][k] * _snd[k][j]) % 1000;
			}
			temp[i][j] %= 1000;
		}
	}

	memcpy(_fst, temp, sizeof(temp));
}

void Solve() {
	while (b > 0) {
		if (b % 2 == 1) {
			MatMul(ans, arr);
		}
		MatMul(arr, arr);
		b /= 2;
	}
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	Init();
	Solve();
	Print();

	return 0;
}