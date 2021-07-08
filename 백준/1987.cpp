#include <bits/stdc++.h>

using namespace std;

int R, C, answer;
int dr[4] = { -1, 1, 0 , 0 };
int dc[4] = { 0, 0, -1 , 1 };
char board[20][20];
bool visited[26];

void dfs(int r, int c, int dist) {
	
	bool canGo = false;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
		char nextAlpha = board[nextR][nextC];
		if (visited[nextAlpha - 'A']) continue;

		canGo = true;
		visited[nextAlpha - 'A'] = true;
		dfs(nextR, nextC, dist + 1);
		visited[nextAlpha - 'A'] = false;
	}

	if (!canGo) {
		answer = max(answer, dist);
		return;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];

	char nextAlpha = board[0][0];
	visited[nextAlpha - 'A'] = true;
	dfs(0, 0, 1);
	
	cout << answer;
}