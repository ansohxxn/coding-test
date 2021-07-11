#include <bits/stdc++.h>

using namespace std;

struct Node { int next, cost; };
vector<vector<Node>> adj_list;
vector<vector<Node>> tree;
int Giga, pole, branch;

void make_tree(int now, int parent) {
	for (int i = 0; i < adj_list[now].size(); ++i) {
		int next = adj_list[now][i].next;
		if (next != parent) {
			tree[now].push_back(adj_list[now][i]);
			make_tree(next, now);
		}
	}
}

void find_pole(int now, int sum) {
	if (tree[now].size() >= 2 || tree[now].empty()) {
		Giga = now;
		pole = sum;
		return;
	}

	int next = tree[now][0].next;
	int nextCost = tree[now][0].cost;
	find_pole(next, sum + nextCost);
}

void find_max_branch(int now, int sum) {
	if (tree[now].empty()) {
		branch = max(branch, sum);
		return;
	}

	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i].next;
		int nextCost = tree[now][i].cost;
		find_max_branch(next, sum + nextCost);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, R;
	cin >> N >> R;

	adj_list.resize(N + 1);
	tree.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		adj_list[node1].push_back({ node2, cost });
		adj_list[node2].push_back({ node1, cost });
	}

	make_tree(R, R);
	find_pole(R, 0);
	find_max_branch(Giga, 0);

	cout << pole << ' ' << branch;
}