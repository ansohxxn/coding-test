#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> graph;
unordered_map<int, int> reserve;
unordered_map<int, int> before;
vector<bool> visited;

void DFS(int num) {
    if (visited[num])
        return;

    if (!visited[before[num]]) {
        reserve[before[num]] = num;
        return;
    }

    visited[num] = true;
    DFS(reserve[num]);
    for (int i = 0; i < graph[num].size(); ++i)
        DFS(graph[num][i]);  
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    graph.resize(n);
    for (int i = 0; i < path.size(); ++i) {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    for (int i = 0; i < order.size(); ++i)
        before[order[i][1]] = order[i][0];

    if (before[0] != 0) return false;

    visited.resize(n);
    visited[0] = true;
    for (int i = 0; i < graph[0].size(); ++i)
        DFS(graph[0][i]);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            answer = false;
            break;
        }
    }

    return answer;
}