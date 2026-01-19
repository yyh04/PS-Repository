#include <iostream>
#include <algorithm>

using namespace std;

string str[20000];

bool compare(string fst, string snd) {

	if (fst.length() < snd.length()) {

		return 1;

	}

	else if (fst.length() > snd.length()) {

		return 0;

	}

	else {

		return fst < snd;

	}

}

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> str[i];

	}

	sort(str, str + n, compare);

	for (int i = 0; i < n; i++) {

		if (i > 0 && str[i] == str[i - 1]) {

			continue;

		}

		cout << str[i] << '\n';

	}

	return 0;

}