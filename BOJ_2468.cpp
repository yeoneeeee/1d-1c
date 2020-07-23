#include <iostream>
#include <vector>
#include <utility> //pair
#include <algorithm> //sort
#include <cstring>
using namespace std;

int N;
int map[101][101];
int visited[101][101] = { 0, };
vector<int> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void search(int x, int y, int height) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && xx <= N && yy >= 0 && yy <= N) {
			if (!visited[xx][yy] && map[xx][yy] > height) {
				search(xx, yy, height);
			}
		}
	}
}

int main() {
	int x;
	int cnt = 1, ans = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			map[i][j] = x;
			v.push_back(x);
		}
	}

	sort(v.begin(), v.end());
	int m = v[0]; //최소높이, 최대높이
	int M = v[v.size() - 1];

	for (int i = m; i < M; i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//방문안했고 높이i+1이상인 영역 찾기
				if (!visited[j][k] && map[j][k] > i) {
					search(j, k, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}