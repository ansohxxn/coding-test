#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, W;
	cin >> N >> W;

	vector<int> adj_count(N + 1);
	for (int i = 1; i <= N - 1; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		++adj_count[n1];
		++adj_count[n2];
	}

	int leaf_count = 0;
	for (int i = 2; i <= N; ++i)
		if (adj_count[i] == 1)
			++leaf_count;

	cout.precision(6);
	cout << fixed << (double)W / leaf_count;
}