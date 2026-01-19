//#include <iostream>
//
//using namespace std;
//
//long long arr_zero_fibonacci[40] = { 0, };
//long long arr_one_fibonacci[40] = { 0, };
//
//long long fibonacci_zero(int);
//long long fibonacci_one(int);
//
//int main(void) {
//
//	ios::sync_with_stdio(false);
//	cout.tie(0);
//	cin.tie(0);
//
//	int t;
//	cin >> t;
//
//	arr_zero_fibonacci[0] = 1;
//	arr_zero_fibonacci[1] = 0;
//	arr_one_fibonacci[0] = 0;
//	arr_one_fibonacci[1] = 1;
//
//	for (int i = 0; i < t; i++) {
//
//		int num;
//		cin >> num;
//
//		fibonacci_zero(num);
//		fibonacci_one(num);
//
//		cout << arr_zero_fibonacci[num] << ' ' << arr_one_fibonacci[num] << '\n';
//
//	}
//
//	return 0;
//
//}
//
//long long fibonacci_zero(int input) {
//
//	if (input <= 1) {
//
//		return input;
//
//	}
//
//	else if (arr_zero_fibonacci[input]) {
//
//		return arr_zero_fibonacci[input];
//
//	}
//
//	else {
//
//		return arr_zero_fibonacci[input] = fibonacci_zero(input - 1) + fibonacci_zero(input - 2);
//
//	}
//
//}
//
//long long fibonacci_one(int input) {
//
//	if (input <= 1) {
//
//		return input;
//
//	}
//
//	else if (arr_one_fibonacci[input]) {
//
//		return arr_one_fibonacci[input];
//
//	}
//
//	else {
//
//		return arr_one_fibonacci[input] = fibonacci_one(input - 1) + fibonacci_one(input - 2);
//
//	}
//
//}

#include <iostream>

using namespace std;

int arr_zero_fibo[41] = { 0, };
int arr_one_fibo[41] = { 0, };

void fibonacci();

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	arr_zero_fibo[0] = 1;
	arr_one_fibo[1] = 1;

	fibonacci();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		int num;
		cin >> num;

		cout << arr_zero_fibo[num] << ' ' << arr_one_fibo[num] << '\n';

	}

	return 0;

}

void fibonacci() {

	for (int i = 2; i < 41; i++) {

		arr_zero_fibo[i] = arr_zero_fibo[i - 1] + arr_zero_fibo[i - 2];
		arr_one_fibo[i] = arr_one_fibo[i - 1] + arr_one_fibo[i - 2];

	}

}