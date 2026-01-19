#include <iostream>

using namespace std;

int Fab, Sab;

void Init() {
	cin >> Sab >> Fab;
}

void Solve() {
	if (Sab > Fab) {
		cout << "flight";
	}
	else {
		cout << "high speed rail";
	}

}
int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	Solve();
	return 0;
}