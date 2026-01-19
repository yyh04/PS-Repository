#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(void) {

	int k, n;
	cin >> k >> n;

	int num;

	for (int i = 0; i < k; i++) {

		cin >> num;
		v.push_back(num);

	}

	return 0;

}