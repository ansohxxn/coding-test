#include <bits/stdc++.h>

using namespace std;

vector<int> segment_tree;
vector<int> arr;

int make_segment_tree(int node, int start, int end) {
    
    if (start == end) {
        segment_tree[node] = arr[start];
        return arr[start];
    }

    int mid = (start + end) / 2;
    int left_result = make_segment_tree(2 * node, start, mid);
    int right_result = make_segment_tree(2 * node + 1, mid + 1, end);
    
    segment_tree[node] = min(left_result, right_result);
    return segment_tree[node];
}

int find_min(int node, int start, int end, const int q_start, const int q_end) {
    
    if (q_end < start || end < q_start) return INT_MAX;
    if (q_start <= start && end <= q_end) return segment_tree[node];

    int mid = (start + end) / 2;
    int left_result = find_min(2 * node, start, mid, q_start, q_end);
    int right_result = find_min(2 * node + 1, mid + 1, end, q_start, q_end);
    
    return min(left_result, right_result);
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
    vector<pair<int, int>> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i].first;
        cin >> queries[i].second;
    }

    int tree_height = (int)ceil(log2(N));
    segment_tree.resize(1 << (tree_height + 1));
    make_segment_tree(1, 0, N - 1);

    for (int i = 0; i < M; ++i)
        cout << find_min(1, 0, N - 1, queries[i].first - 1, queries[i].second - 1) << '\n';
}