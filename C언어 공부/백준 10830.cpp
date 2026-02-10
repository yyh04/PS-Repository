#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int n, b;
int level;
int arr[40][5][5]; // index, r, c
bool visit[40];
int ans[5][5];
int temp[5][5];

void Init() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> b;
    int input;

    for (int i = 0; i < n; i++) {
        arr[0][i][i] = 1;
        ans[i][i] = 1;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> input;
            arr[1][r][c] = input;
        }
    }

    level = log2(b);
}

int* Cal(int _fst, int _snd) {
    if (visit[_fst + _snd] == true) {
        return NULL;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                arr[_fst + _snd][r][c] += arr[_fst][r][i] * arr[_snd][i][c];
            }
        }
    }

    visit[_fst + _snd] = true;
    return 
}

void Multi(int _idx) {
    memcpy(temp, ans, sizeof(ans));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                ans[r][c] += temp[r][i] * arr[_idx][i][c];
            }
        }
    }
}

void Pow(int exp) {
    if (exp == 0) {
        return;
    }
    else if (exp == 1) {
        return;
    }
    else if (exp % 2 == 0) {
        Cal(Cal(exp / 2, exp / 2), );
    }
}

void Solve() {
    for (int i = 0; i < level - 1; i++) {
        Cal(pow(2, i), pow(2, i));
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