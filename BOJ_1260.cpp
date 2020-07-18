#include <iostream>
#include <queue>
#include<cstring> //memset
using namespace std;

int N, M, V;
int visited[1001] = { 0, }; //방문표시
int x[1001][1001]; //인접행렬

void DFS(int V) {
	cout << V << " ";
	visited[V] = 1;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && x[V][i]) {
			DFS(i);
		}
	}
}

void BFS(int V) {
	queue<int> q;
	visited[V] = 1;
	q.push(V);

	while (!q.empty()) {
		V = q.front();
		cout << V << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && x[V][i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		x[a][b] = x[b][a] = 1;
	}

	DFS(V);
	cout << endl;
	memset(visited, 0, sizeof(visited)); //다시 초기화

	BFS(V);
	cout << endl;
	return 0;
}