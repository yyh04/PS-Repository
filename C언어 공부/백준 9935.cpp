#include <iostream>
#include <vector>

using namespace std;

string input;
string boom;
vector<char> tempVec;
vector<pair<int, int>> memoryVec;
bool isInProgress = false;
bool isFRULA = true;
int levelCnt = 0;
int curBoomStringIdx = 0;

void Init() {
	cin >> input;
	cin >> boom;
}

void Solve() {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == boom[0]) { // 폭발 문자열의 첫 번째 문자를 만난 경우
			levelCnt++;
			if (isInProgress) {
				tempVec.push_back(input[i]);
				memoryVec.push_back({levelCnt - 1, curBoomStringIdx});
				curBoomStringIdx = 0;
			}
			else if (tempVec.size() == 0){
				isInProgress = true;
				tempVec.push_back(input[i]);
			}
			else if()
		}
		else if()
	}
}

int main(void) {

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