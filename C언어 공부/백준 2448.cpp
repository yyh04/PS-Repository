#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
pair<int, int> start;
int value1, value2;
vector<vector<char>> vec(3073, vector<char>(6144, ' '));
char tri[3][5] = { {' ', ' ', '*', ' ', ' '},
				   {' ', '*', ' ', '*', ' '},
				   {'*', '*', '*', '*', '*'} };

void Init() {
	cin >> n;
	start = { 1, n - 2 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			vec[start.first + i][start.second + j] = tri[i][j];
		}
	}
}

void Draw(int level) {
	if (n / 3 >= (int)pow(2, level)) {
		value1 = 3 * (int)pow(2, level - 1);
		value2 = 3 * (int)pow(2, level) - 3;
		for (int i = 0; i < value1; i++) {
			for (int j = 0; j < 2 * value1 - 1; j++) {
				vec[start.first + value1 + i][start.second - value2 + j] = vec[1 + i][start.second - (value1 - 3) + j];
				vec[start.first + value1 + i][start.second + 3 + j] = vec[1 + i][start.second - (value1 - 3) + j];
			}
		}
		Draw(level + 1);
	}
}

void Print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n - 1; j++) {
			cout << vec[i][j];
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	Draw(1);
	Print();
	return 0;
}