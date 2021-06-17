#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> child;
int remove_node;

bool is_leaf(int now) {
    if (child[now].empty())
        return true;
    if (child[now].size() == 1 && child[now][0] == remove_node)
        return true;
    return false;
}

int dfs(int now) {

    if (now == remove_node) 
        return 0;
    if (is_leaf(now)) 
        return 1;

    int count = 0;
    for (int i = 0; i < child[now].size(); ++i) 
        count += dfs(child[now][i]);

    return count;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    child.resize(N);
    int root = 0;
    for (int i = 0; i < N; ++i) {
        int parent;
        cin >> parent;

        if (parent == -1)
            root = i;
        else 
            child[parent].push_back(i);
    }

    cin >> remove_node;

    cout << dfs(root);
}