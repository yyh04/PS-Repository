#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;
string order;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {

		cin >> order;
		int num;
		
		if (order == "add") {
			cin >> num;

			if (find(vec.begin(), vec.end(), num) == vec.end()) {

				vec.push_back(num);

			}

		}

		else if (order == "remove") {

			cin >> num;

			if (find(vec.begin(), vec.end(), num) != vec.end()) {

				vec.erase(remove(vec.begin(), vec.end(), num), vec.end());

			}

		}

		else if (order == "check") {

			cin >> num;

			if (find(vec.begin(), vec.end(), num) != vec.end()) {

				cout << 1 << '\n';

			}

			else {

				cout << 0 << '\n';

			}
			
		}

		else if (order == "toggle") {

			cin >> num;

			if (find(vec.begin(), vec.end(), num) != vec.end()) {

				vec.erase(remove(vec.begin(), vec.end(), num), vec.end());

			}

			else if (find(vec.begin(), vec.end(), num) == vec.end()) {

				vec.push_back(num);

			}

		}

		else if (order == "all") {

			vec.clear();

			for (int j = 0; j < 20; j++) {

				vec.push_back(j + 1);

			}

		}

		else if (order == "empty") {

			vec.clear();

		}

	}

	return 0;

}