#include <iostream>
#include <algorithm>

using namespace std;

class Student {

public:

	string name;
	int score;

	Student(string name, int score) {

		this->name = name;
		this->score = score;

	}

	bool operator < (Student &student) {

		return this->score < student.score;

	}

};

int main(void) {

	Student student[] = {

		Student("±è°³¶Ë", 30),
		Student("¹«±ÃÈ­", 50),
		Student("¼±Å©¸²", 20),
		Student("¸¶¿ì½º", 70),
		Student("º§Æ®", 10)

	};

	sort(student, student + 5);

	for (int i = 0; i < 5; i++) {

		cout << student[i].name << ' ';

	}

	return 0;

}