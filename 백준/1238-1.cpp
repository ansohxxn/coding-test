#include <bits/stdc++.h>

using namespace std;

struct Adj { int dest, time; };
struct Town { 
    int num, total_time; 

    bool operator < (const Town& a) const {
        return this->total_time > a.total_time;
    }
};

int N = 0;
vector<vector<Adj>> adj_list;

void dijkstra(vector<int>& dist, int start) {
    
    priority_queue<Town> pq;
    vector<bool> visited(N + 1);

    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        Town now = pq.top();
        pq.pop();

        if (visited[now.num]) continue;
        visited[now.num] = true;

        for (int i = 0; i < adj_list[now.num].size(); ++i) {
            int next = adj_list[now.num][i].dest;
            int next_time = now.total_time + adj_list[now.num][i].time;

            if (dist[next] > next_time) {
                dist[next] = next_time;        
                pq.push({ next, next_time });
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M, X;
    cin >> N >> M >> X;
    adj_list.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int start, dest, time;
        cin >> start >> dest >> time;
        
        adj_list[start].push_back({ dest, time });
    }

    vector<vector<int>> total_dist(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 1; i <= N; ++i) 
        dijkstra(total_dist[i], i);

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        answer = max(answer, total_dist[i][X] + total_dist[X][i]);
    
    cout << answer;
}