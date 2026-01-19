#include <iostream>

using namespace std;

int first(int n) {

	int x = 0;

	for (int i = 1; i <= n; i++) {

		x += i;

	}

	return x;

}

int second(int n) {

	return first(n) * first(n);

}

int third(int n) {

	int x = 0;

	for (int i = 1; i <= n; i++) {

		x += i * i * i;

	}

	return x;

}

int main(void) {

	int n;
	cin >> n;

	cout << first(n) << '\n' << second(n) << '\n' << third(n) << '\n';

}