#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Pos {
	int y;
	int x;
};

void BFS(vector<string>& map, vector<vector<bool>>& checked, int& count, Pos start) {
	queue<Pos> q;
	q.push(start);
	checked[start.y][start.x] = true;
	count = 1;

	int n = map.size();
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			Pos next{ now.y + dy[i], now.x + dx[i] };

			if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
			if (map[next.y][next.x] == '0') continue;
			if (checked[next.y][next.x]) continue;

			checked[next.y][next.x] = true;
			count++;
			q.push(next);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n; 
	vector<string> map(n);
	for (int i = 0; i < n; ++i)
		cin >> map[i];

	vector<int> group;
	vector<vector<bool>> checked(n, vector<bool>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == '1' && !checked[i][j]) {
				Pos start{ i, j };
				int count;
				BFS(map, checked, count, start);

				group.push_back(count);
			}
		}
	}
	cout << group.size() << '\n';
	sort(group.begin(), group.end());
	for (int i = 0; i < group.size(); ++i)
		cout << group[i] << '\n';
}
