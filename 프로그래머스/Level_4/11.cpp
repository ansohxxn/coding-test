#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos { int i, j; };
struct Edge { int cost, graph_1, graph_2; };
bool cmp(const Edge& a, const Edge& b) { return a.cost < b.cost; }

int graph_number[301][301] = { 0 };
vector<Edge> edges;
vector<int> parent;
int group_count = 0;
int N = 0;
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

vector<vector<int>> _land;
int _height;

void BFS(Pos start) {

    queue<Pos> q;
    q.push(start);
    graph_number[start.i][start.j] = ++group_count;

    while (!q.empty()) {
        Pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            Pos next{ now.i + dy[i], now.j + dx[i] };

            if (next.i < 0 || next.i >= N || next.j < 0 || next.j >= N) continue;
            if (graph_number[next.i][next.j] != 0) continue;
            if (abs(_land[now.i][now.j] - _land[next.i][next.j]) <= _height) {
                graph_number[next.i][next.j] = group_count;
                q.push(next);
            }
        }
    }
}

int getParent(int a) {
    if (parent[a] == a) return a;
    return getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;

    N = land.size();
    _land = land;
    _height = height;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (graph_number[i][j] == 0)
                BFS({ i, j });

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 4; ++k) {
                Pos next{ i + dy[k], j + dx[k] };

                if (next.i < 0 || next.i >= N || next.j < 0 || next.j >= N) continue;
                if (graph_number[i][j] == graph_number[next.i][next.j]) continue;
                int cost = abs(_land[i][j] - _land[next.i][next.j]);
                edges.push_back({ cost, graph_number[i][j], graph_number[next.i][next.j] });
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);
    parent.resize(group_count + 1);
    for (int i = 1; i <= group_count; ++i)
        parent[i] = i;
    for (int i = 0; i < edges.size(); ++i) {
        if (getParent(edges[i].graph_1) != getParent(edges[i].graph_2)) {
            answer += edges[i].cost;
            unionParent(edges[i].graph_1, edges[i].graph_2);
        }
    }

    return answer;
}