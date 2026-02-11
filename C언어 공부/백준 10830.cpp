#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int n, b;
long long origin[5][5];
long long I[5][5];
int visit[40];

void Init() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> b;
    int input;

    for (int i = 0; i < n; i++) {
        I[i][i] = 1;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> input;
            origin[r][c] = input;
        }
    }
}

int (*Cal(const int _fst[5][5], const int _snd[5][5]), int _exp)[5] {
    int returnArr[5][5];

    if (visit[_exp] == true) {
        memcpy(returnArr, arr[_fst + _snd], sizeof(arr[_fst + _snd]));
        return returnArr;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int i = 0; i < n; i++) {
                arr[_fst + _snd][r][c] += arr[_fst][r][i] * arr[_snd][i][c];
            }
        }
    }

long long (*Pow(long long _fst, long long _snd, int exp))[5] {
    long long returnArr[5][5];

    if (exp == 0) {
        return I;
    }
    else if (exp == 1) {
        return origin;
    }
    else if (exp % 2 == 0) {
        return Cal(exp / 2, exp / 2);
    }
    else if (exp % 2 == 1) {
        return Cal(exp / 2, exp / 2);
    }
}

void Solve() {
    Pow(b);
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

//#include <iostream>
//#include <cmath>
//#include <string.h>
//
//using namespace std;
//
//int n, b;
//int level;
//int arr[40][5][5]; // index, r, c
//bool visit[40];
//int ans[5][5];
//int temp[5][5];
//
//void Init() {
//    ios::sync_with_stdio(false);
//    cout.tie(0);
//    cin.tie(0);
//
//    cin >> n >> b;
//    int input;
//
//    for (int i = 0; i < n; i++) {
//        arr[0][i][i] = 1;
//        ans[i][i] = 1;
//    }
//
//    for (int r = 0; r < n; r++) {
//        for (int c = 0; c < n; c++) {
//            cin >> input;
//            arr[1][r][c] = input;
//        }
//    }
//
//    level = log2(b);
//}
//
//int (*Cal(const int _fst[5][5], const int _snd[5][5]))[5] {
//    int returnArr[5][5];
//
//    if (visit[_fst + _snd] == true) {
//        memcpy(returnArr, arr[_fst + _snd], sizeof(arr[_fst + _snd]));
//        return returnArr;
//    }
//
//    for (int r = 0; r < n; r++) {
//        for (int c = 0; c < n; c++) {
//            for (int i = 0; i < n; i++) {
//                arr[_fst + _snd][r][c] += arr[_fst][r][i] * arr[_snd][i][c];
//            }
//        }
//    }
//
//    visit[_fst + _snd] = true;
//    memcpy(returnArr, arr[_fst + _snd], sizeof(arr[_fst + _snd]));
//    return returnArr;
//}
//
//void Multi(int _idx) {
//    memcpy(temp, ans, sizeof(ans));
//
//    for (int r = 0; r < n; r++) {
//        for (int c = 0; c < n; c++) {
//            for (int i = 0; i < n; i++) {
//                ans[r][c] += temp[r][i] * arr[_idx][i][c];
//            }
//        }
//    }
//}
//
//int (*Pow(int exp))[5] {
//    int returnArr[5][5];
//
//    if (exp == 0) {
//        memcpy(returnArr, arr[0], sizeof(arr[0]));
//        return returnArr;
//    }
//    else if (exp == 1) {
//        memcpy(returnArr, arr[1], sizeof(arr[1]));
//        return returnArr;
//    }
//    else if (exp % 2 == 0) {
//        return Cal(exp / 2, exp / 2);
//    }
//    else if (exp % 2 == 1) {
//        return Cal(exp / 2, exp / 2);
//    }
//}
//
//void Solve() {
//    Pow(b);
//}
//
//void Print() {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << arr[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}
//
//int main(void) {
//    Init();
//    Solve();
//    Print();
//
//    return 0;
//}