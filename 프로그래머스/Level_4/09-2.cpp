#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<int>> graph;
unordered_map<int, int> reserve;
unordered_map<int, int> before;
vector<bool> checked;

void BFS() {
    queue<int> q;
    checked[0] = true;
    q.push(0);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if (checked[next]) continue;
            if (!checked[before[next]]) {
                reserve[before[next]] = next;
                continue;
            }
            q.push(next);
            checked[next] = true;
            if (reserve.find(next) != reserve.end()) {
                q.push(reserve[next]);
                checked[reserve[next]] = true;
            }
                
        }
    }
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

    checked.resize(n);
    BFS();

    for (int i = 0; i < n; ++i) {
        if (!checked[i]) {
            answer = false;
            break;
        }
    }

    return answer;
}