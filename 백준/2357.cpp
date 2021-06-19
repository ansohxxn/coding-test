#include <bits/stdc++.h>

using namespace std;

struct Node { int min, max; };
vector<int> arr;
vector<Node> segtree;

Node init_segtree(int node, int start, int end) {
	
	if (start == end) {
		segtree[node].min = arr[start];
		segtree[node].max = arr[start];
		return segtree[node];
	}

	int mid = (start + end) / 2;
	Node left_res = init_segtree(2 * node, start, mid);
	Node right_res = init_segtree(2 * node + 1, mid + 1, end);

	segtree[node].min = min(left_res.min, right_res.min);
	segtree[node].max = max(left_res.max, right_res.max);

	return segtree[node];
}

Node search_segtree(int node, int start, int end, const int q_start, const int q_end) {
	
	if (q_end < start || end < q_start) return { INT_MAX, INT_MIN };
	if (q_start <= start && end <= q_end) return segtree[node];

	int mid = (start + end) / 2;
	Node left_res = search_segtree(2 * node, start, mid, q_start, q_end);
	Node right_res = search_segtree(2 * node + 1, mid + 1, end, q_start, q_end);

	Node mid_res;
	mid_res.min = min(left_res.min, right_res.min);
	mid_res.max = max(left_res.max, right_res.max);

	return mid_res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int tree_height = (int)ceil(log2(N));
	int tree_size = 1 << (tree_height + 1);
	segtree.resize(tree_size);
	init_segtree(1, 0, N - 1);

	for (int i = 0; i < M; ++i) {
		int q_start, q_end;
		cin >> q_start >> q_end;

		Node result = search_segtree(1, 0, N - 1, q_start - 1, q_end - 1);
		cout << result.min << ' ' << result.max << '\n';
	}
}