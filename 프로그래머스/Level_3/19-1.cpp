#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 20000000
#define num first 
#define cost second 

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.cost > b.cost;
    }
};

void dijkstra(vector<int>& taxi_cost, vector<vector<int>>& graph, int& n, int& start) {
    int result = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({ start, 0 });
    taxi_cost[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().num;
        int nowCost = pq.top().cost;
        pq.pop();
           
        for (int i = 1; i <= n; ++i) {

            if (graph[now][i] == 0)
                continue;

            if (taxi_cost[i] > nowCost + graph[now][i]) {
                taxi_cost[i] = nowCost + graph[now][i];
                pq.push({ i, nowCost + graph[now][i] });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < fares.size(); ++i) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    vector<int> StoI_cost(n + 1, INF);
    dijkstra(StoI_cost, graph, n, s);
    
    vector<int> AtoI_cost(n + 1, INF);
    dijkstra(AtoI_cost, graph, n, a);
    
    vector<int> BtoI_cost(n + 1, INF);
    dijkstra(BtoI_cost, graph, n, b);

    for (int i = 1; i <= n; ++i) {
        int result = StoI_cost[i] + AtoI_cost[i] + BtoI_cost[i];
        if (answer > result)
            answer = result;
    }

    return answer;
}