#include <bits/stdc++.h>
 
using namespace std;

vector<int> parent;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void connect(int a, int b) {
    int par_a = getParent(a);
    int par_b = getParent(b);
    if (par_a < par_b) parent[par_b] = par_a;
    else parent[par_a] = parent[par_b];
}

bool isConnected(int a, int b) {
    int par_a = getParent(a);
    int par_b = getParent(b);
    if (par_a == par_b) return true;
    else return false;
}

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    long long total_cost = 0;
    vector<vector<int>> road_cost(M, vector<int>(3));
    for (int i = 0; i < M; ++i) {
        cin >> road_cost[i][0] >> road_cost[i][1] >> road_cost[i][2];
        total_cost += road_cost[i][2];
    }
        
    sort(road_cost.begin(), road_cost.end(), cmp);

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    long long all_connect_cost = 0;
    for (int i = 0; i < road_cost.size(); ++i) {
        if (!isConnected(road_cost[i][0], road_cost[i][1])) {
            connect(road_cost[i][0], road_cost[i][1]);
            all_connect_cost += road_cost[i][2];
        }
    }

    bool isAllConnected = true;
    for (int i = 2; i <= N; ++i) {
        if (!isConnected(parent[1], parent[i])) {
            isAllConnected = false;
            break;
        }
    }

    if (isAllConnected) cout << total_cost - all_connect_cost;
    else cout << -1;
}
