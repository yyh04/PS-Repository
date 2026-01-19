#include <iostream>
#include <vector>
#define NUM 1000000007

using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix operator * (const Matrix& A, const Matrix& B) {
	Matrix C = { {0, 0}, {0, 0} };
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				C[i][j] += ((A[i][k] % NUM) * (B[k][j] % NUM)) % NUM;
				C[i][j] %= NUM;
			}
		}
	}
	return C;
}

Matrix sol = { {1, 0}, {0, 1} };
Matrix mat = { {1, 1}, {1, 0} };
long long n;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	while (n > 0) {
		if (n & 1) {
			sol = sol * mat;
		}
		mat = mat * mat;
		n = n >> 1;
	}
	cout << sol[0][1] << '\n';
	return 0;
}