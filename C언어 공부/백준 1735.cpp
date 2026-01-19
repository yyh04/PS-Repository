#include <iostream>

using namespace std;

long long gcd(long long, long long);

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int an, ad;
	int bn, bd;
	long long max;
	long long cn, cd;
	cin >> an >> ad;
	cin >> bn >> bd;

	an *= bd;
	bn *= ad;

	cn = an + bn;
	cd = ad * bd;

	if (cn >= cd) {

		max = gcd(cn, cd);

	}

	else {

		max = gcd(cd, cn);

	}

	cn /= max;
	cd /= max;

	cout << cn << ' ' << cd;

	return 0;

}

long long gcd(long long fst, long long snd) {

	if (fst % snd == 0) {

		return snd;

	}

	return gcd(snd, fst % snd);

}