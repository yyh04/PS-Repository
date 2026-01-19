#include <iostream>
#include <map>

using namespace std;

map<string, string, greater<string>> m;

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		string name, enterOrLeave;
		cin >> name >> enterOrLeave;

		m[name] = enterOrLeave;

	}

	for (auto it = m.begin(); it != m.end(); it++) {

		if (it->second == "enter") {

			cout << it->first << '\n';

		}

	}

	return 0;

}