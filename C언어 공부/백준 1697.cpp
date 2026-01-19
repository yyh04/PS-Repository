#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int);

bool visitied[100001] = { 0, };
int subin, littleSubin;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> subin >> littleSubin;

	BFS(subin);

	return 0;

}

void BFS(int fst) {

	queue<pair<int, int>> q;
	int cnt = 0;

	visitied[fst] = true;
	q.push({ fst, cnt });

	while (!q.empty()) {

		int np = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (np == littleSubin) {

			cout << cnt;
			break;

		}

		if (0 <= np + 1 && np + 1 <= 100000 && !visitied[np + 1]) {
			
			q.push({ np + 1, cnt + 1 });
			visitied[np + 1] = true;

		}

		if (0 <= np - 1 && np - 1 <= 100000 && !visitied[np - 1]) {

			q.push({ np - 1, cnt + 1 });
			visitied[np - 1] = true;

		}

		if (0 <= np * 2 && np * 2 <= 100000 && !visitied[np * 2]) {

			q.push({ np * 2,  cnt + 1 });
			visitied[np * 2] = true;

		}

	}

}