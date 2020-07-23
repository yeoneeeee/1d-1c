#include <iostream>
#include <vector>
#include <queue>
#include <utility> //pair
#include <cstring> //memset
#include <algorithm> //sort
using namespace std;

int M, N, K;
int visited[101][101] = { 0, };
int board[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt = 1;

void search(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < M && yy >= 0 && yy < N) {
				if (!visited[xx][yy] && !board[xx][yy]) {
					cnt++;
					search(xx, yy);
				}
			}
		}
	}
}

int main() {
	vector<int> ans;
	int ans_cnt = 0;
	cin >> M >> N >> K;

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> y1 >> x1 >> y2 >> x2;

		for (int j = x1; j <= x2-1; j++) {
			for (int k = y1; k <= y2-1; k++) {
				board[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!board[i][j] && !visited[i][j]) {
				search(i, j);
				ans.push_back(cnt);
				cnt = 1;
				ans_cnt++;
			}
		}
	}

	cout << ans_cnt << '\n';
	
	sort(ans.begin(), ans.end()); //오름차순 정렬
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}