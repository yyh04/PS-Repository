#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {

	if (a.second.first == b.second.first) {

		return a.second.second > b.second.second;

	}

	else {

		return a.second.first > b.second.first;

	}

}

int main(void) {

	vector<pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("김개똥", pair<int, int>(90, 20040824)));
	v.push_back(pair<string, pair<int, int>>("아무개", pair<int, int>(90, 20040924)));
	v.push_back(pair<string, pair<int, int>>("에어팟", pair<int, int>(95, 20040328)));
	v.push_back(pair<string, pair<int, int>>("마우스", pair<int, int>(30, 20070912)));
	v.push_back(pair<string, pair<int, int>>("안경집", pair<int, int>(90, 19990223)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {

		cout << v[i].first << ' ';

	}

	return 0;

}