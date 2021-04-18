#include <string>
#include <vector>

using namespace std;

long long answer = 0;
void DFS(vector<vector<int>>& graph, vector<long long>& sum, int now, int parent) {
    for (int i = 0; i < graph[now].size(); ++i)
        if (graph[now][i] != parent)
            DFS(graph, sum, graph[now][i], now);
    sum[parent] += sum[now];
    answer += abs(sum[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {

    vector<long long> sum(a.size());
    for (int i = 0; i < a.size(); ++i) sum[i] = a[i];

    vector<vector<int>> graph(a.size());
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    DFS(graph, sum, 0, 0);
    
    if (sum[0] == 0) return answer;
    else return - 1;
}