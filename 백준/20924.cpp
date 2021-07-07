#include <bits/stdc++.h>

using namespace std;

int N, R;
struct Node { int next, cost; };
vector<vector<Node>> tree;
vector<bool> visited;
int giga_node, pole, branch;

void find_pole(int now, int totalCost) {
	
	bool giga_exist = tree[now].size() > 2 || (now == R && tree[now].size() == 2);
	bool giga_not_exist = (now != R && tree[now].size() == 1) || (now == R && tree[now].size() == 0);
	if (giga_exist || giga_not_exist) {
		giga_node = now;
		pole = totalCost;
		return;
	}

	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i].next;
		int nextCost = tree[now][i].cost;
		if (!visited[next]) {
			visited[next] = true;
			find_pole(next, totalCost + nextCost);
		}
	}
}

void find_max_branch(int now, int totalCost) {

	bool isLeaf = tree[now].size() == 1;
	if (isLeaf) {
		branch = max(branch, totalCost);
		return;
	}

	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i].next;
		int nextCost = tree[now][i].cost;
		if (!visited[next]) {
			visited[next] = true;
			find_max_branch(next, totalCost + nextCost);
			visited[next] = false;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> R;

	tree.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;
		
		tree[node1].push_back({ node2, cost });
		tree[node2].push_back({ node1, cost });
	}

	visited[R] = true;
	find_pole(R, 0);
	find_max_branch(giga_node, 0);

	cout << pole << ' ' << branch;
}