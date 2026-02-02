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

//1. 폭발 문자열에 포함되지 않는 문자는 바로 출력한다.
//2. 폭발 문자열의 가장 첫 번째 문자를 만나면 일단 킵한다.
//(1) 첫 번째 폭발 문자 다음 또 다시 첫 번째 폭발 문자를 만나는 경우
//- 다시 만난 첫 번째 폭발 문자로 시작하는 폭발 문자열인지 확인한다.
//(2) 첫 번째 폭발 문자 다음 두 번째 폭발 문자를 만나는 경우
//- 첫 번째 폭발 문자로 시작하는 폭발 문자열인지 확인한다.
//(3) 첫 번째 폭발 문자 다음 폭발 문자가 아닌 문자를 만나는 경우
//- 폭발 문자열이 될 수 없으므로 탐색한 문자열을 모두 출력한다.
//(4) 첫 번째 폭발 문자 다음 두 번째가 아닌 나머지 폭발 문자를 만나는 경우
//- 폭발 문자열이 될 수 없으므로 탐색한 문자열을 모두 출력한다.