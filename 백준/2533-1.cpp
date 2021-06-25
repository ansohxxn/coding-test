#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj_list;
int dp[1000001][2];

int DFS(int now, int parent, bool state) {
	
	if (dp[now][state] != -1)
		return dp[now][state];

	if (state == true) {
		dp[now][state] = 1;
		for (int i = 0; i < adj_list[now].size(); ++i) {
			int next = adj_list[now][i];
			if (next != parent) 
				dp[now][state] += min(DFS(next, now, true), DFS(next, now, false));
		}
	}
	if (state == false) {
		dp[now][state] = 0;
		for (int i = 0; i < adj_list[now].size(); ++i) {
			int next = adj_list[now][i];
			if (next != parent) 
				dp[now][state] += DFS(next, now, true);
		}
	}

	return dp[now][state];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	adj_list.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout << min(DFS(1, 1, true), DFS(1, 1, false));
}