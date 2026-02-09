#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int n, b;
int level;
int arr[5][5];
int origin[5][5];
int temp[5][5];

void Init() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> b;
    int input;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> input;
            origin[r][c] = input;
        }
    }

    memcpy(arr, origin, sizeof(origin));
    level = log2(b);
}

void Square() {
    memcpy(temp, arr, sizeof(arr));
    memset(arr, 0, sizeof(arr));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                arr[r][c] += temp[r][i] * temp[i][c];
            }
        }
    }
}

void Multi() {
    memcpy(temp, arr, sizeof(arr));
    memset(arr, 0, sizeof(arr));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                arr[r][c] += temp[r][i] * origin[i][c];
            }
        }
    }
}

void Solve() {
    for (int i = 0; i < level - 1; i++) {
        Square();
    }
    if (b % 2 != 0) {
        Multi();
    }
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    Init();
    Solve();
    Print();

    return 0;
}