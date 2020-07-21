#include <iostream>
#include <queue>
using namespace std;

int N, M, u, v;
int visited[1001] = { 0, }; // 행 단위로 방문처리
int graph[1001][1001] = { 0, };
//queue<int> q; // 행 단위로 큐에 push할 예정
int ans = 0;
//int start;

void search(int x) {
	visited[x] = 1;

	for (int i = 0; i < N; i++) {
		if (!visited[i] && graph[x][i]) {
			search(i);
		}
	}

	/*
	visited[x] = 1;
	N--;
	//x행 탐색 : [x][i]가 1이고(연결) i행 방문안했으면 - push
	for (int i = 0; i < N; i++) {
		if (graph[x][i] == 1 && !visited[i]) { 
			q.push(i);
			visited[i] = 1;
		}
	}*/
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u - 1][v - 1] = graph[v-1][u-1] = 1;
		//start = u - 1; //탐색 시작할 행 위치
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			search(i);
			ans++;
		}
	}

	/*
	q.push(start); 
	while (N) {
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			search(x);
			cout << x << '\n';
		}
		ans++;
		
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				search(i);
				//cout << i << '\m';
			}
		}
	}*/

	cout << ans << '\n';
	return 0;
}