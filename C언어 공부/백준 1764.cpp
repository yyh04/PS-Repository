#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, pair<bool, bool>> p;
int cnt = 0;
vector<string> nameList;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	string name;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> name;
		p.insert({ name,{true, false} });

	}

	for (int i = 0; i < m; i++) {

		cin >> name;

		if (p.find(name) != p.end() && p.find(name)->second.first == true) {

			cnt++;
			nameList.push_back(name);

		}

	}

	sort(nameList.begin(), nameList.end());

	cout << cnt << '\n';

	for (int i = 0; i < nameList.size(); i++) {

		cout << nameList[i] << '\n';

	}

}