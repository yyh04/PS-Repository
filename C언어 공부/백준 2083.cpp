#include <iostream>

using namespace std;

int main(void) {
	string name = "0";
	int age, weight;

	while (1) {
		cin >> name >> age >> weight;
		if (name == "#") {
			return 0;
		}
		if (age > 17 || weight >= 80) {
			cout << name << ' ' << "Senior\n";
		}
		else {
			cout << name << ' ' << "Junior\n";
		}
	}

	return 0;
}