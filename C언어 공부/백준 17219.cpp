#include <iostream>
#include <map>

using namespace std;

map<string, string> p;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string site;
	string pw;

	for (int i = 0; i < n; i++) {

		cin >> site;
		cin >> pw;

		p.insert({ site, pw });

	}

	for (int i = 0; i < m; i++) {

		cin >> site;
		cout << p.find(site)->second << '\n';

	}

	return 0;

}
