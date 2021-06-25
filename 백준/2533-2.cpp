#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj_list;
int dp[1000001][2];

void DFS(int now, int parent) {
	
	dp[now][0] = 0;
	dp[now][1] = 1;
	for (int i = 0; i < adj_list[now].size(); ++i) {
		int next = adj_list[now][i];
		if (next != parent) {
			DFS(next, now);
			dp[now][0] += dp[next][1];
			dp[now][1] += min(dp[next][0], dp[next][1]);
		}	
	}
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

	DFS(1, 1);
	cout << min(dp[1][0], dp[1][1]);
}