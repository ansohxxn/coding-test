#include <bits/stdc++.h>

using namespace std;

int countSubtree(vector<vector<int>>& adj_list, vector<int>& subtree, int now, int parent) {
    int sum = 1;
    for (int i = 0; i < adj_list[now].size(); ++i) {
        int next = adj_list[now][i];
        if (next != parent) 
            sum += countSubtree(adj_list, subtree, next, now);
    }
    subtree[now] = sum;
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;
    vector<vector<int>> adj_list(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }
    vector<int> query(Q);
    for (int i = 0; i < Q; ++i)
        cin >> query[i];

    vector<int> subtree(N + 1);
    countSubtree(adj_list, subtree, R, -1);

    for (int i = 0; i < Q; ++i) 
        cout << subtree[query[i]] << '\n';
}