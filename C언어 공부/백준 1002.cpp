#include<iostream>
#include<cmath>

using namespace std;

int T;
int x1, x2, Y1, y2, r1, r2;

double Distance(int px1, int pY1, int px2, int py2) {
	return sqrt((px1 - px2) * (px1 - px2) + (pY1 - py2) * (pY1 - py2));
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2;
		int bigr = max(r1, r2);
		int smallr = min(r1, r2);
		double distance = Distance(x1, Y1, x2, y2);
		//cout << "distance = " << distance << '\n';
		if (x1 == x2 && Y1 == y2 && r1 == r2) {
			cout << "-1\n";
		}
		else if (distance > (double)(r1 + r2)) {
			cout << "0\n";
		}
		else if (distance == (double)(r1 + r2)) {
			cout << "1\n";
		}
		else if (distance < (double)(r1 + r2)) {
			if ((double)bigr > distance + (double)smallr) {
				cout << "0\n";
			}
			else if ((double)bigr == distance + (double)smallr) {
				cout << "1\n";
			}
			else if ((double)bigr < distance + (double)smallr) {
				cout << "2\n";
			}
		}
	}
	return 0;
}