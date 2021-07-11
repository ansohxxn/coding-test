#include <bits/stdc++.h>

using namespace std;

int N, R;
struct Node { int next, cost; };
vector<vector<Node>> tree;
int giga_node, giga_parent, pole, branch;

void find_pole(int now, int parent, int totalCost) {

	bool giga_exist = tree[now].size() > 2 || (now == R && tree[now].size() == 2);
	bool giga_not_exist = (now != R && tree[now].size() == 1) || (now == R && tree[now].size() == 0);
	if (giga_exist || giga_not_exist) {
		giga_parent = parent;
		giga_node = now;
		pole = totalCost;
		return;
	}

	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i].next;
		int nextCost = tree[now][i].cost;
		if (next != parent)
			find_pole(next, now, totalCost + nextCost);
	}
}

void find_max_branch(int now, int parent, int totalCost) {

	bool isLeaf = tree[now].size() == 1;
	if (isLeaf) {
		branch = max(branch, totalCost);
		return;
	}

	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i].next;
		int nextCost = tree[now][i].cost;
		if (next != parent)
			find_max_branch(next, now, totalCost + nextCost);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> R;

	tree.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		tree[node1].push_back({ node2, cost });
		tree[node2].push_back({ node1, cost });
	}

	find_pole(R, R, 0);
	find_max_branch(giga_node, giga_parent, 0);

	cout << pole << ' ' << branch;
}