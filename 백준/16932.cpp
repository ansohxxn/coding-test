#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct Pos { int x, y; };

int bfs(vector<vector<int>>& board, vector<vector<int>>& groups, int& num, Pos start) {
	queue<Pos> q;
	q.push(start);
	groups[start.x][start.y] = num;
	int count = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (board[nextX][nextY] == 0) continue;
			if (groups[nextX][nextY] == -1) {
				groups[nextX][nextY] = num;
				q.push({ nextX, nextY });
				++count;
			}
		}
	}
	return count;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	vector<vector<int>> groups(N, vector<int>(M, -1));
	vector<int> group_cnt;
	int num = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (groups[i][j] == -1 && board[i][j] == 1) {
				group_cnt.push_back(bfs(board, groups, num, { i, j }));
				++num;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 0) {
				set<int> s;
				for (int k = 0; k < 4; ++k) {
					int nextX = i + dx[k];
					int nextY = j + dy[k];
					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
					if (board[nextX][nextY] == 0) continue;
					s.insert(groups[nextX][nextY]);
				}
				int tmp = 1;
				for (auto& group : s)
					tmp += group_cnt[group];
				answer = max(answer, tmp);
			}
		}
	}
	cout << answer;
}