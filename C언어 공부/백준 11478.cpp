#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	string temp;

	for (int i = 0; i < str.size(); i++) {

		temp = "";

		for (int j = i; j < str.size(); j++) {

			temp += str[j];
			s.insert(temp);

		}

	}

	cout << s.size() << '\n';

	return 0;

}