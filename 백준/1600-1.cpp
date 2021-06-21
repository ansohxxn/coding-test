#include <bits/stdc++.h>

using namespace std;

int dirR[4] = { -1, 1, 0, 0 };
int dirC[4] = { 0, 0, -1, 1 };
int knight_dirR[8] = { -1, -2, -1, -2, 1, 2, 1, 2 };
int knight_dirC[8] = { -2, -1, 2, 1, -2, -1, 2, 1 };
struct Pos { int r, c, use_knight; };

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K, C, R;
	cin >> K >> C >> R;
	vector<vector<int>> board(R, vector<int>(C));
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];
 

	queue<Pos> q;
	vector<vector<vector<int>>> dist(R, vector<vector<int>>(C, vector<int>(K + 1, -1)));
	
	q.push({ 0, 0, 0 });
	for (int i = 0; i < K; ++i)
		dist[0][0][i] = 0;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextR = now.r + dirR[i];
			int nextC = now.c + dirC[i];

			if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
			if (board[nextR][nextC] == 1) continue;
			if (dist[nextR][nextC][now.use_knight] != -1) continue;

			dist[nextR][nextC][now.use_knight] = dist[now.r][now.c][now.use_knight] + 1;
			q.push({ nextR, nextC, now.use_knight });
		}

		if (now.use_knight == K) continue;
		for (int i = 0; i < 8; ++i) {
			int nextR = now.r + knight_dirR[i];
			int nextC = now.c + knight_dirC[i];
			
			if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
			if (board[nextR][nextC] == 1) continue;
			if (dist[nextR][nextC][now.use_knight + 1] != -1) continue;

			dist[nextR][nextC][now.use_knight + 1] = dist[now.r][now.c][now.use_knight] + 1;
			q.push({ nextR, nextC, now.use_knight + 1 });
		}
	}

	int answer = INT_MAX;
	for (int i = 0; i <= K; ++i) 
		if (dist[R - 1][C - 1][i] != -1)
			answer = min(answer, dist[R - 1][C - 1][i]);
	
	if (answer == INT_MAX) cout << -1;
	else cout << answer;
}