#include <iostream>
#include <map>

using namespace std;

map<int, pair<bool, bool>> p;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int num;
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {

		cin >> num;
		p.insert({ num,{true,false} });

	}

	for (int i = 0; i < b; i++) {

		cin >> num;

		if (p.find(num) == p.end()) { // 교집합이 아닌 경우

			p.insert({ num,{false, true} });

		}

		else if (p.find(num) != p.end()) { // 교집합인 경우

			p.erase(p.find(num));

		}

	}

	cout << p.size() << '\n';

	return 0;

}