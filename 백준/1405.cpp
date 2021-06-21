#include <bits/stdc++.h>

using namespace std;

int N;
double answer;
int vert[4] = { 0, 0, 1, -1 };
int horiz[4] = { 1, -1, 0, 0 };
double dir_prob[4];
#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3

void DFS(vector<vector<bool>>& visited, double prob, int nowR, int nowC, int depth) {
	if (depth == N) {
		answer += prob;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int nextR = nowR + vert[i];
		int nextC = nowC + horiz[i];

		if (!visited[nextR][nextC]) {
			visited[nextR][nextC] = true;
			DFS(visited, prob * (dir_prob[i] / 100), nextR, nextC, depth + 1);
			visited[nextR][nextC] = false;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> dir_prob[EAST] >> dir_prob[WEST] >> dir_prob[SOUTH] >> dir_prob[NORTH];

	vector<vector<bool>> visited(2 * N + 1, vector<bool>(2 * N + 1));
	visited[N][N] = true;
	DFS(visited, 1.0, N, N, 0);

	cout << fixed;
	cout.precision(10);
	cout << answer;
}