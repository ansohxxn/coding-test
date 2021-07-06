#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct Pos { int x, y; };
int Map[1000][1000];
int Dist[1000][1000];

void bfs(Pos dest) {
	queue<Pos> q;
	vector<vector<bool>> visited(N, vector<bool>(M));

	q.push(dest);
	Dist[dest.x][dest.y] = 0;
	visited[dest.x][dest.y] = true;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (Map[nextX][nextY] == 0) continue;
			if (visited[nextX][nextY]) continue;

			q.push({ nextX, nextY });
			Dist[nextX][nextY] = Dist[now.x][now.y] + 1;
			visited[nextX][nextY] = true;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Pos dest;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				dest.x = i;
				dest.y = j;
			}
		}
	}

	bfs(dest);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (Dist[i][j] == 0 && Map[i][j] == 1)
				cout << -1 << ' ';
			else
				cout << Dist[i][j] << ' ';
		}	
		cout << '\n';
	}
}