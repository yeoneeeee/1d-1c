#include <iostream>
#include <queue>
#include <utility> //pair
#include <cstring> //memset
using namespace std;

int T, M, N, K;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int box[51][51] = { 0, };
int visited[51][51] = { 0, };
int ans = 0;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if ((next_x >= 0 && next_x < M) && (next_y >= 0 && next_y < N)) {
				if (!visited[next_x][next_y] && box[next_x][next_y]) {
					q.push(make_pair(next_x,next_y));
					visited[next_x][next_y] = 1;
				}
			}
		}
	}
	
}

int main() {
	cin >> T;
	
	int m, n; int x, y;
	for (int i = 0; i < T; i++) {
		memset(box, 0, sizeof(box));
		memset(visited, 0, sizeof(visited));
		ans = 0;

		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> m >> n;
			box[m][n] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && box[i][j]) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}