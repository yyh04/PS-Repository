#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> str;

int GetSum(string serial) {

	int sum = 0;
	int n = serial.length();

	for (int k = 0; k < n; k++) {

		if (0 <= serial[k] - '0' && serial[k] - '0' <= 9) {

			sum += serial[k] - '0';

		}

	}

	return sum;

}

bool compare(string fst, string snd) {

	if (fst.length() != snd.length()) {

		return fst.length() < snd.length();

	}

	else {

		if (GetSum(fst) != GetSum(snd)) {

			return GetSum(fst) < GetSum(snd);

		}

		else {

			return fst < snd;

		}

	}

}

int main(void) {

	int n;
	cin >> n;

	string input;

	for (int i = 0; i < n; i++) {

		cin >> input;
		str.push_back(input);

	}

	sort(str.begin(), str.end(), compare);

	for (int i = 0; i < n; i++) {

		cout << str[i] << '\n';

	}

	return 0;

}