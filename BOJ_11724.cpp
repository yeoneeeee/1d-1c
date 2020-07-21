#include <iostream>
#include <queue>
using namespace std;

int N, M, u, v;
int visited[1001] = { 0, }; // �� ������ �湮ó��
int graph[1001][1001] = { 0, };
//queue<int> q; // �� ������ ť�� push�� ����
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
	//x�� Ž�� : [x][i]�� 1�̰�(����) i�� �湮�������� - push
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
		//start = u - 1; //Ž�� ������ �� ��ġ
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