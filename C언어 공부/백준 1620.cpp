#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> p;
string name[100000];
string inputName;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> name[i];
		p.insert({ name[i], i + 1 });

	}

	for (int i = 0; i < m; i++) {

		cin >> inputName;

		if (isdigit(inputName[0])) {

			cout << name[stoi(inputName) - 1] << '\n';

		}

		else {

			cout << p.find(inputName)->second << '\n';

		}

	}

	return 0;

}