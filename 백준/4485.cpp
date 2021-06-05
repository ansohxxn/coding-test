#include <bits/stdc++.h>

using namespace std;

#define MAX 140625
int N = 0;
int cave[125][125];
struct Pos { int x, y, cost; };
struct cmp {
	bool operator() (const Pos& a, const Pos& b) {
		return a.cost > b.cost;
	}
};

int dijikstra(Pos start) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	priority_queue<Pos, vector<Pos>, cmp> pq;
	vector<vector<int>> black_rupees(N, vector<int>(N, MAX));

	pq.push(start);
	black_rupees[start.x][start.y] = start.cost;

	while (!pq.empty()) {
		Pos now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = now.x + dx[i];
			int next_y = now.y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;

			int next_cost = now.cost + cave[next_x][next_y];
			if (black_rupees[next_x][next_y] > next_cost) {
				black_rupees[next_x][next_y] = next_cost;
				pq.push({ next_x, next_y, next_cost });
			}
		}
	}

	return black_rupees[N - 1][N - 1];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int count = 0;
	while(true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> cave[i][j];
		cout << "Problem " << ++count << ": " << dijikstra({ 0, 0, cave[0][0] }) << '\n';
	} 
}
