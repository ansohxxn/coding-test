#include <bits/stdc++.h>

using namespace std;

vector<long long> histogram;
vector<int> segtree;
int N;

int init_segtree(int node, int start, int end) {
	
	if (start == end) 
		return segtree[node] = start;

	int mid = (start + end) / 2;
	int left_res = init_segtree(2 * node, start, mid);
	int right_res = init_segtree(2 * node + 1, mid + 1, end);

	if (histogram[left_res] < histogram[right_res])
		return segtree[node] = left_res;
	else
		return segtree[node] = right_res;
}

int search_segtree(int node, int start, int end, const int query_start, const int query_end) {

	if (end < query_start || query_end < start)
		return -1; 
	if (query_start <= start && end <= query_end)
		return segtree[node];

	int mid = (start + end) / 2;
	int left_res = search_segtree(2 * node, start, mid, query_start, query_end);
	int right_res = search_segtree(2 * node + 1, mid + 1, end, query_start, query_end);

	if (left_res == -1)
		return right_res;
	else if (right_res == -1)
		return left_res;
	else {
		if (histogram[left_res] < histogram[right_res])
			return left_res;
		else
			return right_res;
	}
}

long long get_area_max(int query_start, int query_end) {
	
	int mid = search_segtree(1, 0, N - 1, query_start, query_end);
	int min_height = histogram[mid];
	int width = query_end - query_start + 1;
	
	long long mid_area = (long long)min_height * width;
	if (query_start < mid) {
		long long left_area = get_area_max(query_start, mid - 1);
		mid_area = max(mid_area, left_area);
	}
	if (query_end > mid) {
		long long right_area = get_area_max(mid + 1, query_end);
		mid_area = max(mid_area, right_area);
	}

	return mid_area;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N;
	histogram.resize(N);
	for (int i = 0; i < N; i++)
		cin >> histogram[i];

	int tree_height = (int)ceil(log2(N));
	segtree.resize(1 << (tree_height + 1));
	init_segtree(1, 0, N - 1);

	cout << get_area_max(0, N - 1);
}