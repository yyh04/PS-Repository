#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int t;
	cin >> t;

	long long num;
	long long sqrtNum;
	bool isPrime = false;

	for (int i = 0; i < t; i++) {

		isPrime = false;
		cin >> num;

		while (isPrime == false) {

			if (num == 0) {

				num++;
				continue;

			}

			if (num == 1) {

				num++;
				continue;

			}

			if (num == 2 || num == 3) {

				isPrime = true;
				break;

			}
			
			sqrtNum = sqrt(num);

			for (int j = 2; j <= sqrtNum; j++) {

				if (num % j == 0) {

					num++;
					break;

				}

				if (j == sqrtNum) {

					isPrime = true;

				}

			}

		}

		cout << num << '\n';

	}
	
	return 0;

}