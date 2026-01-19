#include <iostream>
#include <queue>

using namespace std;

int main(void) {

	queue<int> q;

	for (int i = 0; i < 9; i++) {

		int num;
		cin >> num;

		q.push(num);

	}

	q.pop();
	q.pop();

	cout << "q의 사이즈는 " << q.size() << "입니다.\n";

	while (!q.empty()) {

		cout << q.front() << ' ';

		q.pop();

	}

	return 0;

}