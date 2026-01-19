#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int adjVertex[1001][1001] = { 0, };
int visited[1001] = { 0, };

void init(int n);
void DFS(int n, int v);
void BFS(int n, int v);

int main(void) {

	int n, m, v;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {

		int f, s;

		scanf("%d %d", &f, &s);

		adjVertex[f][s] = 1;
		adjVertex[s][f] = 1;

	}

	DFS(n, v);
	BFS(n, v);

	return 0;

}

void DFS(int n, int v) {

	printf("%d ", v);

	visited[v] = 1;

	for (int adj = 1; adj <= n; adj++) {

		if (!visited[adj] && adjVertex[v][adj]) {

			DFS(n, adj);

		}

	}

}