#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 9999
int answer;
int north;

void DFS(vector<int>& weak, vector<int>& dist, int depth, int start_weak_pos, int weak_visited) {
  
    if (depth == dist.size())
        return;
    
    if (depth + 1 >= answer)
        return;

    for (int i = 0; i < weak.size(); ++i) {
        // 시계 방향
        int next_weak_pos = (start_weak_pos + i) % weak.size();
        int distance = weak[next_weak_pos] - weak[start_weak_pos];
        if (next_weak_pos < start_weak_pos)
            distance += north;

        if (distance <= dist[depth]) 
            weak_visited |= (1 << next_weak_pos);
        else break;
    }

    if (weak_visited == (1 << weak.size()) - 1) {
        answer = min(answer, depth + 1);
        return;
    }

    for (int i = 0; i < weak.size(); ++i) {
        if (weak_visited & (1 << i)) 
            continue;
        DFS(weak, dist, depth + 1, i, weak_visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = INF;
    north = n;
    sort(dist.begin(), dist.end(), greater<>());

    for (int i = 0; i < weak.size(); ++i) 
        DFS(weak, dist, 0, i, 0);
    
    if (answer == INF) return -1;
    return answer;
}