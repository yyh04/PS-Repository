#include <iostream>
#include <vector>

using namespace std;

void DFS(int);

vector<int> arr[20001];
int visitied[20001][2] = { 0, };

bool visit = 0;
bool value = 1;
int o;

vector<string> result;

int main(void) {

	int k;
	cin >> k;

	for (o = 0; o < k; o++) {

		int v, e;
		cin >> v >> e;

		for (int i = 0; i < 20001; i++) {

			arr[i].clear();

			for (int j = 0; j < 2; j++) {

				visitied[i][j] = 0;

			}

		}

		result.push_back("YES");

		for (int j = 0; j < e; j++) {

			int from, to;
			cin >> from >> to;

			arr[from].push_back(to);
			arr[to].push_back(from);

		}

		visitied[1][value] = 1;
		DFS(1);

		for (int i = 2; i <= v; i++) {

			if (!visitied[i][visit]) {

				visitied[i][value] = 1;
				DFS(i);

			}

		}

	}

	for (int i = 0; i < k; i++) {

		cout << result[i] << '\n';

	}

	return 0;

}

void DFS(int start) {

	if (visitied[start][visit]) {

		return;

	}

	visitied[start][visit] = true;

	for (int i = 0; i < arr[start].size(); i++) {

		if (visitied[arr[start][i]][value] == 0) {

			if (visitied[start][value] == 1) {

				visitied[arr[start][i]][value] = 2;

			}

			else if (visitied[start][value] == 2) {

				visitied[arr[start][i]][value] = 1;

			}

		}

		else if (visitied[arr[start][i]][value] != 0) {

			if (visitied[start][value] == visitied[arr[start][i]][value]) {

				result[o] = "NO";

			}

		}

	}

	for (int i = 0; i < arr[start].size(); i++) {

		DFS(arr[start][i]);

	}

}