#include <bits/stdc++.h>

using namespace std;

struct Edge { int a, b, cost; };
bool cmp(const Edge& a, const Edge& b) { return a.cost < b.cost; }
int parent[301];

int get_root(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = get_root(parent[x]);
}

void union_graph(int a, int b) {
	int par_a = get_root(a);
	int par_b = get_root(b);
	if (par_a < par_b) parent[par_b] = par_a;
	else parent[par_a] = par_b;
}

bool is_same_graph(int a, int b) {
	int par_a = get_root(a);
	int par_b = get_root(b);
	if (par_a == par_b) return true;
	else return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	vector<Edge> edges;
	for (int i = 1; i <= N; ++i) {
		int cost;
		cin >> cost;
		edges.push_back({ 0, i, cost });
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int cost;
			cin >> cost;

			if (i != j) 
				edges.push_back({ i, j, cost });
		}
	}

	sort(edges.begin(), edges.end(), cmp);

	for (int i = 0; i <= N; ++i)
		parent[i] = i;

	int total_cost = 0;
	for (int i = 0; i < edges.size(); ++i) {
		if (is_same_graph(edges[i].a, edges[i].b) == false) {
			union_graph(edges[i].a, edges[i].b);
			total_cost += edges[i].cost;
		}
	}
	cout << total_cost;
}