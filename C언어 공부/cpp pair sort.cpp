#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

	vector<pair<int, string>> v;

	v.push_back(pair<int, string>(80, "김개똥"));
	v.push_back(pair<int, string>(30, "아무개"));
	v.push_back(pair<int, string>(60, "마우스"));
	v.push_back(pair<int, string>(50, "프라다"));
	v.push_back(pair<int, string>(90, "비주얼"));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		cout << v[i].second << ' ';

	}

	return 0;

}