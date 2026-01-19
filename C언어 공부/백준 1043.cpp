#include <iostream>
#include <vector>

using namespace std;

vector<int> Link[51];
vector<int> tStamp[51];
bool visit[51];
bool know[51];
bool flag;
int n, m;
int start = 0;
int ans = 0;

void Init() {
	cin >> n >> m;
	int kMan;
	cin >> kMan;
	vector<int> v1;
	for (int i = 0; i < kMan; i++) {
		int input;
		cin >> input;
		v1.push_back(input);
		start = input;
		know[input] = true;
	}
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1.size(); j++) {
			if (j == i) {
				continue;
			}
			Link[v1[i]].push_back(v1[j]);
			Link[v1[j]].push_back(v1[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vector<int> v2;
		for (int j = 0; j < num; j++) {
			int input;
			cin >> input;
			v2.push_back(input);
			tStamp[i].push_back(input);
		}
		for (int j = 0; j < v2.size(); j++) {
			for (int k = 0; k < v2.size(); k++) {
				if (k == j) {
					continue;
				}
				Link[v2[j]].push_back(v2[k]);
				Link[v2[k]].push_back(v2[j]);
			}
		}
	}
}

void DFS(int start) {
	visit[start] = true;
	know[start] = true;
	for (int i = 0; i < Link[start].size(); i++) {
		if (visit[Link[start][i]] == false) {
			DFS(Link[start][i]);
		}
	}
}

void Solve() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < tStamp[i].size(); j++) {
			if (know[tStamp[i][j]] == true) {
				flag = true;
			}
		}
		if (flag == false) {
			ans++;
		}
		flag = false;
	}
	cout << ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	Init();
	DFS(start);
	Solve();
	return 0;
}