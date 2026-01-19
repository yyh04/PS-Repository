#include <iostream>

using namespace std;

string str;
bool flag = false;

void Init() {
	cin >> str;
}

void Solve() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'I' || str[i] == 'O' || str[i] == 'S' || str[i] == 'H' || str[i] == 'Z' || str[i] == 'X' || str[i] == 'N') {
			continue;
		}
		else {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "NO";
	}
	else {
		cout << "YES";
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