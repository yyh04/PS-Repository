#include <iostream>

using namespace std;

int down, up;

int Solve(int _up) {
	if (_up == 1)
		return down;
	if (_up % 2 == 1)
		return down * Solve(_up - 1);

	int p = Solve(_up / 2);
	return p * p;
}

int main(void) {
	cin >> down >> up;

	cout << Solve(up);
	return 0;

}