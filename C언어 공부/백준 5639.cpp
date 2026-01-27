#include <iostream>

using namespace std;

int tree[10001];
int arr[10001];

void Init() {
	int input;
	int idx = 0;

	while (1) {
		cin >> input;

		if (cin.eof() == true) {
			break;
		}

		arr[idx++] = input;
	}

	tree[0] = arr[0];
}

int SearchParentsNode(int __input, int __curIdx) {
	int parentsNodeIdx = (__curIdx - 1) / 2;

	if (tree[parentsNodeIdx] > __input) {
		return SearchParentsNode(__input, parentsNodeIdx);
	}
	else if (tree[parentsNodeIdx] < __input) {
		return parentsNodeIdx;
	}
	else {
		cout << "SearchParentsNode(" << __input << ", " << __curIdx << ") Error\n";
		return;
	}
}

void Fill(int _input, int _curIdx) { // tree에 이미 값이 있을 수도 있음 @@@@@@@@@@
	if (tree[_curIdx] > _input) {
		tree[_curIdx * 2 + 1] = _input;
	}
	else if(tree[_curIdx] < _input) {
		int parentsNodeIdx = SearchParentsNode(_input, _curIdx);
		tree[parentsNodeIdx] = _input;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();

	return 0;
}