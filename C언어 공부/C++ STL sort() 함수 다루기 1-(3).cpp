#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int first, int second) {

	return first > second;

}

int main(void) {

	int arr[10] = { 3, 2, 4, 3, 4, 1, 1, 3, 5, 4 };

	sort(arr, arr + 10, compare);

	for (int i = 0; i < 10; i++) {

		cout << arr[i] << ' ';

	}

}