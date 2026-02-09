#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string input;
string boom;
deque<int> keepQue;
bool isFRULA = true;

void Init() {
	cin >> input;
	cin >> boom;
}

void CoughUp() {
	isFRULA = false;

	while (!keepQue.empty()) {
		for (int j = 0; j < keepQue.front() + 1; j++) {
			cout << boom[j];
		}
		keepQue.pop_front();
	}
}

void Solve() {
	for (int i = 0; i < input.size(); i++) {
		if (!keepQue.empty() && input[i] == boom[keepQue.back() + 1]) {
			keepQue.back()++;
		}
		else if (input[i] == boom[0]) {
			keepQue.push_back(0);
		}
		else {
			isFRULA = false;

			if (keepQue.empty()) {
				cout << input[i];
			}
			else {
				CoughUp();
				cout << input[i];
			}
		}

		if (!keepQue.empty() && boom.size() == keepQue.back() + 1) {
			keepQue.pop_back();
		}
	}

	if (!keepQue.empty()) {
		CoughUp();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	Init();
	Solve();

	if (isFRULA) {
		cout << "FRULA";
	}

	return 0;
}