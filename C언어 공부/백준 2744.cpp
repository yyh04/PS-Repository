#include <iostream>

using namespace std;

int main(void) {

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {

		char c;

		if ('a' <= str[i] && str[i] <= 'z') {

			c = str[i] - 'a' + 'A';
			cout << c;

		}

		else {

			c = str[i] - 'A' + 'a';
			cout << c;

		}

	}	

	return 0;

}