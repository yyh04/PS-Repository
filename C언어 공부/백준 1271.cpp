#include <iostream>

using namespace std;

int main(void) {

	int money, num;
	cin >> money >> num;

	int a = money / num;
	int b = money % num;

	cout << a << ' ' << b;

	return 0;

}