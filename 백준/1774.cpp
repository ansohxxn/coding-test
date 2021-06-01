#include <bits/stdc++.h>

using namespace std;

struct Pos { int x, y; };
struct Edge { int num1, num2; double cost; };
vector<int> parent;

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void connect(int a, int b) {
	int par_a = getParent(a);
	int par_b = getParent(b);
	if (par_a < par_b) parent[par_b] = par_a;
	else parent[par_a] = par_b;
}

bool isConnected(int a, int b) {
	int par_a = getParent(a);
	int par_b = getParent(b);
	if (par_a == par_b) return true;
	else return false;
}

bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}

double getDistance(Pos pos1, Pos pos2) {
	return sqrt(pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2));
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;
	vector<Pos> pos(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> pos[i].x;
		cin >> pos[i].y;
	}
	vector<pair<int, int>> connected(M);
	for (int i = 0; i < M; ++i) {
		cin >> connected[i].first;
		cin >> connected[i].second;
	}


	vector<Edge> edges;
	for (int i = 1; i <= N - 1; ++i)
		for (int j = i + 1; j <= N; ++j)
			edges.push_back({ i, j, getDistance(pos[i], pos[j]) });
	sort(edges.begin(), edges.end(), cmp);


	parent.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	for (int i = 0; i < M; ++i)
		connect(connected[i].first, connected[i].second);

	double connect_cost = 0.0f;
	for (int i = 0; i < edges.size(); ++i) {
		if (isConnected(edges[i].num1, edges[i].num2) == false) {
			connect(edges[i].num1, edges[i].num2);
			connect_cost += edges[i].cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << connect_cost;
}
