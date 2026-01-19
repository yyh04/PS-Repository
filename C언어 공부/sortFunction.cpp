#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int arr[10] = { 3, 5, 4, 2, 1, 8, 6, 7, 10, 9 };
	sort(arr, arr + 10, compare);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}