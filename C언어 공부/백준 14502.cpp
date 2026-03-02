#include <iostream>
#include <vector>

using namespace std;

int lab[10][10];
bool virusVisit[10][10];
bool wallVisit[10][10];
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
int n, m;

void Init() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	int input;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			lab[i][j] = input;

			if (input == 1) {
				wall.push_back({ i, j });
				wallVisit[i][j] = true;
			}
			if (input == 2) {
				virus.push_back({ i, j });
				virusVisit[i][j] = true;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		lab[0][i] = 1;
		lab[9][i] = 1;
		lab[i][0] = 1;
		lab[i][9] = 1;
	}
}

void SetWall() {
}

int main(void) {

	return 0;
}