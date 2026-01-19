#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int first, int second){
	return first > second;
}

int main(void) {
	int arr[] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };

	sort(arr, arr + 10, compare);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}