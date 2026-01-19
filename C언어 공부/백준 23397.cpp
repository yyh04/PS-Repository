#include <iostream>
#include <vector>

using namespace std;

int t, d, m;
bool flag = false;
vector<int> vec;

void Init() {
	cin >> t >> d >> m;
	int input;
	vec.push_back(0);
	for (int i = 0; i < m; i++) {
		cin >> input;
		vec.push_back(input);
	}
	vec.push_back(d);
}

void Solve() {
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] - vec[i - 1] >= t) {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "Y";
	}
	else {
		cout << "N";
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