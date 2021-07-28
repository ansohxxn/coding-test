#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& checked, int now) {
	cout << now << ' ';
	for (int i = 0; i < graph[now].size(); ++i) {
		int next = graph[now][i];
		if (!checked[next]) {
			checked[next] = true;
			DFS(graph, checked, next);
		}
	}
}

void BFS(vector<vector<int>>& graph, vector<bool>& checked, int start) {
	queue<int> q;
	q.push(start);
	checked[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			if (!checked[next]) {
				checked[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m, start;
	cin >> n; cin >> m; cin >> start;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i) {
		int v1, v2; cin >> v1; cin >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 1; i <= n; ++i)
		sort(graph[i].begin(), graph[i].end());

	vector<bool> checked_dfs(n + 1);
	checked_dfs[start] = true;
	DFS(graph, checked_dfs, start);
	cout << '\n';

	vector<bool> checked_bfs(n + 1);
	BFS(graph, checked_bfs, start);
}