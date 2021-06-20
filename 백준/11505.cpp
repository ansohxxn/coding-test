#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;
vector<long long> segtree;

#define MOD 1'000'000'007

long long init_segtree(int node, int start, int end) {
	
	if (start == end) 
		return segtree[node] = arr[start];

	int mid = (start + end) / 2;
	long long left_res = init_segtree(2 * node, start, mid);
	long long right_res = init_segtree(2 * node + 1, mid + 1, end);

	segtree[node] = (left_res * right_res) % MOD;
	return segtree[node];
}

long long search_segtree(int node, int start, int end, const int& q_start, const int& q_end) {
	
	if (q_end < start || end < q_start) return 1;
	if (q_start <= start && end <= q_end) return segtree[node];

	int mid = (start + end) / 2;
	long long left_res = search_segtree(2 * node, start, mid, q_start, q_end);
	long long right_res = search_segtree(2 * node + 1, mid + 1, end, q_start, q_end);

	return (left_res * right_res) % MOD;
}

long long update_segtree(int node, int start, int end, const int& index, const long long& new_value) {
	
	if (index < start || index > end) return segtree[node];
	if (start == end) 
		return segtree[node] = new_value;
	
	int mid = (start + end) / 2;
	long long left_res = update_segtree(2 * node, start, mid, index, new_value);
	long long right_res = update_segtree(2 * node + 1, mid + 1, end, index, new_value);

	segtree[node] = (left_res * right_res) % MOD;
	return segtree[node];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int tree_height = (int)ceil(log2(N));
	int tree_size = 1 << (tree_height + 1);
	segtree.resize(tree_size);
	init_segtree(1, 0, N - 1);

	for (int i = 0; i < M + K; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) 
			update_segtree(1, 0, N - 1, b - 1, c);
		if (a == 2) 
			cout << search_segtree(1, 0, N - 1, b - 1, c - 1) << '\n';
	}
}