#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int, int);

vector<int> v;
vector<int> dist;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	int divisor;
	int num;
	int cnt = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {

		cin >> n;
		v.push_back(n);

	}

	sort(v.begin(), v.end());

	for (int i = 1; i < num; i++) {

		dist.push_back(v[i] - v[i - 1]);

	}

	sort(dist.begin(), dist.end());

	for (int i = 1; i < num - 1; i++) {

		divisor = gcd(dist[i], dist[0]);
		dist[0] = divisor;

	}

	cout << ((v.back() - v.front()) / divisor) - v.size() + 1;

	return 0;


}

int gcd(int fst, int snd) {

	if (fst % snd == 0) {

		return snd;

	}

	return gcd(snd, fst % snd);

}