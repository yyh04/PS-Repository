#include <iostream>
#include <stack>

using namespace std;

int main(void) {

	stack<int> stack;

	for (int i = 0; i < 9; i++) {

		int num;
		cin >> num;

		stack.push(num);

	}

	stack.pop();
	stack.pop();

	while (!stack.empty()) {

		cout << stack.top() << ' ';
		stack.pop();

	}

	return 0;

}