#include <iostream>

using namespace std;

int m;
int n, s;
unsigned long long X;
unsigned long long arr[10001];
unsigned long long square[10001][31];
unsigned long long ans;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	X = 1000000007;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> n >> s;
		arr[i] = s;
		square[i][0] = n;
		square[i][30] = 1;
	}
}

void Square(unsigned long long _input, int _m, int _idx) {
	square[_m][_idx] = ((_input % X) * (_input % X)) % X;
}

void Solve() {
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < 30; j++) {
			Square(square[i][j - 1], i, j);
		}
	}

	for (int i = 0; i < m; i++) {
		square[i][30] = ((square[i][0] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][2] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][9] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][11] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][14] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][15] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][17] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][19] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][20] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][23] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][24] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][25] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][27] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][28] % X) * (square[i][30] % X)) % X;
		square[i][30] = ((square[i][29] % X) * (square[i][30] % X)) % X;
		ans = (((square[i][30] % X) * (arr[i] % X) % X) + (ans % X)) % X;
	}
}

void Print() {
	cout << ans;
}

int main(void) {
	Init();
	Solve();
	Print();
	return 0;
}