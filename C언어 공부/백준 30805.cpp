#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arrN[101];
int arrM[101];
int tmp[101];

vector<int> vec;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int input;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		arrN[i] = input;
		tmp[input]++;
	}

	for (int i = 1; i <= m; i++) {
		cin >> input;
		arrM[i] = input;
		tmp[input]++;

		if (tmp[input] == 2) {
			vec.push_back(input);
		}
	}

}

void Solve() {
	if (vec.empty()) {
		cout << 0 << '\n';
	}


}

int main(void) {

	return 0;
}