#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
int leaf_count = 0;
int root = 1;

void DFS(int now, int parent) {
	
	int child_size = adj_list[now].size();
	if (now != root) child_size -= 1;

	if (child_size == 0) {
		++leaf_count;
		return;
	}

	for (int i = 0; i < adj_list[now].size(); ++i) {
		int next = adj_list[now][i];
		if (next != parent)
			DFS(next, now);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, W;
	cin >> N >> W;

	adj_list.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}

	DFS(root, root);
	cout.precision(6);
	cout << fixed << (double)W / leaf_count;
}